#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "math3d.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);

GLuint createHandClock(GLuint* vbo, GLuint* ebo);

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

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

    GLuint vao, vbo, ebo;
    vao = createHandClock(&vbo, &ebo);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    GLfloat currentTime = 0.0f;
    GLfloat elapsedTime = 0.0f;
    GLfloat oldTime     = 0.0f;
    GLfloat time = 0.0f;

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        currentTime = (GLfloat)glfwGetTime();
        elapsedTime += currentTime - oldTime;
        oldTime     = currentTime;

        if(elapsedTime > 1.0f)
        {
            time+= M_PI/30;
            elapsedTime = 0.0f;
        }

        Matrix3x3 rotation;
        Vector3 z = { 0.0f, 0.0f, -1.0f };

        Matrix3x3MakeRotation(&z, time, &rotation);

        glUniformMatrix3fv(
            glGetUniformLocation(shaderProgram, "rotation"),1,GL_TRUE,(GLfloat*)rotation.m);
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"), 1.0f, 1.0f, 1.0f, 1.0f);

        glBindVertexArray(vao);
        glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, (GLvoid*)0);
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
    GLfloat vertices[] = 
    {
        0.0f,0.0f,0.0f,
        0.0f,0.5f,0.0f
    };

    GLuint elements[] = 
    {
        0,1
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
