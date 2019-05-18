#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include <GL/glew.h>
#include "math3d.h"

class Heightmap
{
public:
    Heightmap(GLuint resx, GLuint resz, GLuint numComp);
    ~Heightmap();

    void draw(GLuint shaderProgram, const Matrix4x4& mvp, const Matrix4x4& model, GLuint texture = 0);

private:
    GLuint mResx;
    GLuint mResz;

    GLuint mVao;
    GLuint mVbo;
    GLuint mEbo;
};

#endif // HEIGHTMAP_H
