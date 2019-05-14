#include <iostream>
#include <cstdlib>
#include <FreeImage.h>

#include "heightmap.h"
#include "math3d.h"

Heightmap::Heightmap(GLuint resx, GLuint resz, GLuint numComp) :
    mResx(resx),
    mResz(resz)
{
    FREE_IMAGE_FORMAT format = FreeImage_GetFileType("Heightmap.png");

    if(format == FIF_UNKNOWN)
    {
        std::cerr << "Unknown image format" << std::endl;

        exit(1);
    }

    FIBITMAP* heightmap = FreeImage_Load(format, "Heightmap.png");
    FIBITMAP* heightmap32;

    GLint bpp = FreeImage_GetBPP(heightmap);

    if(bpp == 32)
    {
        heightmap32 = heightmap;
    }
    else
    {
        heightmap32 = FreeImage_ConvertTo32Bits(heightmap);

        FreeImage_Unload(heightmap);
    }

    GLuint width = FreeImage_GetWidth(heightmap32);
    GLuint height = FreeImage_GetHeight(heightmap32);

    GLfloat* vertices = new GLfloat[(resx + 1) * (resz + 1) * numComp];
    GLuint* elements  = new GLuint[resx * resz * 6];

    GLfloat* v = vertices;
    for(GLuint z = 0; z <= resz; z++)
    {
        for(GLuint x = 0; x <= resx; x++)
        {
            GLfloat s = x / (GLfloat)(resx);
            GLfloat t = z / (GLfloat)(resz);

            GLuint pixelx = s * width;
            GLuint pixely = t * height;

            RGBQUAD pixel;
            FreeImage_GetPixelColor(heightmap32, pixelx, pixely, &pixel);

            // Set position
            *v++ = s;
            *v++ = pixel.rgbRed / 255.0f;
            *v++ = t;

            // Skip normals
            v += 3;

            // Set texture coordinates
            *v++ = 10.0f * s;
            *v++ = 10.0f * t;
        }
    }

    GLuint* el = elements;
    for (GLuint z = 0; z < resz; z++)
    {
        for (GLuint x = 0; x < resx; x++)
        {
            int e0 = (resx + 1) * z + x;
            int e1 = e0 + 1;
            int e2 = e0 + (resx + 1);
            int e3 = e2 + 1;

            *el++ = e0;
            *el++ = e2;
            *el++ = e1;
            *el++ = e1;
            *el++ = e2;
            *el++ = e3;
        }
    }

    calcNormals(elements, mResx * mResz * 6, vertices, (mResx + 1) * (mResz + 1), 8);

    glGenVertexArrays(1, &mVao);
    glGenBuffers(1, &mVbo);
    glGenBuffers(1, &mEbo);

    glBindVertexArray(mVao);

    glBindBuffer(GL_ARRAY_BUFFER, mVbo);
    glBufferData(GL_ARRAY_BUFFER, (resx + 1) * (resz + 1) * numComp * sizeof(GLfloat),
                 vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, resx * resz * 6 * sizeof(GLuint),
                 elements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, numComp * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, numComp * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, numComp * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    delete[] vertices;
    delete[] elements;
}

Heightmap::~Heightmap()
{
    glDeleteVertexArrays(1, &mVao);
    glDeleteBuffers(1, &mVbo);
    glDeleteBuffers(1, &mEbo);
}

void Heightmap::draw(GLuint shaderProgram, const Matrix4x4& mvp, const Matrix4x4& model, GLuint texture)
{
    glUseProgram(shaderProgram);

    if(texture != 0)
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        glUniform1i(glGetUniformLocation(shaderProgram, "sampler"), 0);
    }

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"),
                       1, GL_TRUE, (GLfloat*)model.m);

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "mvp"),
                       1, GL_TRUE, (GLfloat*)mvp.m);

    glBindVertexArray(mVao);
    glDrawElements(GL_TRIANGLES, mResx * mResz * 6, GL_UNSIGNED_INT, (GLvoid*)0);
    glBindVertexArray(0);
}
