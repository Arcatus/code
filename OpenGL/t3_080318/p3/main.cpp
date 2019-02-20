#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "math3d.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);
void poll_keyboard(GLFWwindow* window);

GLuint createCatmullRom(GLuint* vbo, GLuint n);

int main()
{
    glfwSetErrorCallback(error_callback);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Curva de Hermit",NULL, NULL);

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

    GLuint vao, vbo, n = 20;
    vao = createCatmullRom(&vbo, n);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        poll_keyboard(window);

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glBindVertexArray(vao);

        glDrawArrays(GL_LINE_STRIP,0,n*4);

        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    glfwTerminate();
}

GLuint createCatmullRom(GLuint* vbo, GLuint n)
{
    GLfloat vertices[ (n + 1) * 3 * 6 ] = { };

    GLfloat inc = (GLfloat) 1 / n;

    GLfloat CtrlP[] = 
    {
         0.3f,  1.0f, 4.0f, 3.0f, 1.0f, 4.0f, 5.86,
         1.38f, 1.0f, 0.5f, 4.0f, 4.0f, 5.0f, 2.41
    };

    Matrix4x4 MCR = {
         0.0f,-0.5f, 1.0f,-0.5f, 
         1.0f, 0.0f,-2.5f, 1.5f,
         0.0f, 0.5f, 2.0f,-1.5f,
         0.0f, 0.0f,-0.5f, 0.5f,
    };

    Matrix4x4 parametrizacion;
    Matrix4x4InitToZero(&parametrizacion);

    parametrizacion.m[0][0] = 1.0f;

    GLuint nP = 7;

    GLuint index = 0;

    for (int j = 1; j < nP-2; ++j)
    {
        Matrix4x4 G = {
             CtrlP[j - 1],  CtrlP[j + 0],  CtrlP[j + 1],  CtrlP[j + 2],
            CtrlP[j+nP-1], CtrlP[j+nP+0], CtrlP[j+nP+1], CtrlP[j+nP+2],
            0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f
        };

        Matrix4x4 Ct = G * MCR;

        for (GLfloat i = 0; i <= 1.0f; i +=inc)
        {
            parametrizacion.m[1][0] = i;
            parametrizacion.m[2][0] = i*i;
            parametrizacion.m[3][0] = i*i*i;

            Matrix4x4 tmp = Ct * parametrizacion;
 
            vertices[3 * index + 0] = tmp.m[0][0] ;
            vertices[3 * index + 1] = tmp.m[1][0] ;
            vertices[3 * index + 2] = 0.0f;
            index++;
        }
    }

    GLuint vao;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return vao;
}


void error_callback(GLint error, const GLchar* description)
{
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;

    std::fflush(stdin);
    std::cin.get();

    exit(1);
}

void poll_keyboard(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
