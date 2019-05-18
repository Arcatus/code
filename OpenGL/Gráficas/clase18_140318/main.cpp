#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "texture.h"

void error_callback(GLint error, const GLchar* description);

GLuint createModel(GLuint* vbo, GLuint* ebo);

int main()
{
    glfwSetErrorCallback(error_callback);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(512, 512, "OpenGLApp",NULL,NULL);

    if(!window)
    {
        std::cerr << "GLFW error: Can't create window." << std::endl;

        return 1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "GLEW error: " << glewGetErrorString(status) << std::endl;

        return 1;
    }

    GLint numTextures;
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &numTextures);
    std::cout << numTextures << std::endl;

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");

    GLuint vao, vbo, ebo, texture0, texture1;
    vao = createModel(&vbo, &ebo);
    texture0 = createTextureObject("461223128.jpg");
    texture1 = createTextureObject("bricks_hole.jpg");

    glViewport(0, 0, 512, 512);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture0);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture1);

        glUniform1i(glGetUniformLocation(shaderProgram, "sampler0"), 0);
        glUniform1i(glGetUniformLocation(shaderProgram, "sampler1"), 1);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    glfwTerminate();

    return 0;
}

void error_callback(GLint error, const GLchar* description)
{
    std::cerr << "GLFW error: " << description << std::endl;

    exit(1);
}

GLuint createModel(GLuint* vbo, GLuint* ebo)
{
    GLfloat vertices[] =
    {
        -0.5f, -0.5f, 0.0f,      0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,      1.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,      0.0f, 1.0f,
         0.5f,  0.5f, 0.0f,      1.0f, 1.0f,
    };

    GLuint elements[] =
    {
        0, 1, 2,
        1, 3, 2
    };

    GLuint vao;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return vao;
}
