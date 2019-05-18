#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);

GLuint createHandClock(GLuint* vbo, GLuint* ebo);
GLuint createIndicator(GLuint* vbo, GLuint* ebo);

int main()
{
    glfwSetErrorCallback(error_callback);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGLApp",NULL, NULL);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "GLEW Error: " << glewGetErrorString(status) << std::endl;

        std::fflush(stdin);
        std::cin.get();

        return 1;
    }

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl",
                                             "fragment_shader.glsl");

    GLuint vao, vbo, ebo;
    vao = createHandClock(&vbo, &ebo);

    GLuint vaoi, vboi, eboi;
    vaoi = createIndicator(&vboi, &eboi);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    GLfloat currentTime = 0.0f;
    GLfloat elapsedTime = 0.0f;
    GLfloat oldTime     = 0.0f;

    GLuint index = 0;

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        currentTime = (GLfloat)glfwGetTime();
        elapsedTime += currentTime - oldTime;
        oldTime     = currentTime;

        if(elapsedTime > 1.0f)
        {
            index = (index + 2) % 120;
            elapsedTime = 0.0f;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glUniform1i(glGetUniformLocation(shaderProgram, "isHandClock"),
                    GL_TRUE);
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"),
                    1.0f, 1.0f, 1.0f, 1.0f);

        glBindVertexArray(vao);
        glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, (GLvoid*)(index * sizeof(GLuint)));
        glBindVertexArray(0);

        glUniform1i(glGetUniformLocation(shaderProgram, "isHandClock"),
                    GL_FALSE);
        glUniform3f(glGetUniformLocation(shaderProgram, "displacement"),
                    0.0f, 0.5f, 0.0f);
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"),
                    0.0f, 1.0f, 0.0f, 1.0f);

        glBindVertexArray(vaoi);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glUniform3f(glGetUniformLocation(shaderProgram, "displacement"),
                    0.0f, -0.5f, 0.0f);

        glBindVertexArray(vaoi);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glUniform3f(glGetUniformLocation(shaderProgram, "displacement"),
                    0.5f, 0.0f, 0.0f);
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"),
                    0.0f, 0.0f, 1.0f, 1.0f);

        glBindVertexArray(vaoi);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glUniform3f(glGetUniformLocation(shaderProgram, "displacement"),
                   -0.5f,  0.0f, 0.0f);

        glBindVertexArray(vaoi);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    glfwTerminate();
}

void error_callback(GLint error, const GLchar* description)
{
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;

    std::fflush(stdin);
    std::cin.get();

    exit(1);
}

GLuint createHandClock(GLuint* vbo, GLuint* ebo)
{
    GLfloat* vertices = new GLfloat[3 * 61];
    vertices[0] = 0.0f;
    vertices[1] = 0.0f;
    vertices[2] = 0.0f;

    for(GLuint i = 1; i < 61; i++)
    {
        vertices[3 * i]     = 0.5f * sinf(2 * M_PI * i / 60);
        vertices[3 * i + 1] = 0.5f * cosf(2 * M_PI * i / 60);
        vertices[3 * i + 2] = 0.0f;
    }

    GLuint* elements = new GLuint[120];

    for(GLuint i = 0; i < 60; i++)
    {
        elements[2 * i]     = 0;
        elements[2 * i + 1] = i + 1;
    }

    GLuint vao;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, 3 * 61 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 120 * sizeof(GLuint), elements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    delete[] vertices;
    delete[] elements;

    return vao;
}

GLuint createIndicator(GLuint* vbo, GLuint* ebo)
{
    GLfloat vertices[] =
    {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
    };

    GLuint elements[] =
    {
        0, 1, 2,
        1, 3, 2,
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return vao;

}
