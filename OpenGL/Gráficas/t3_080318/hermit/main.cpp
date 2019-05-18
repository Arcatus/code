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
GLuint createHermit(GLuint* vbo, const GLuint n);

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

    GLuint vao, vbo, n = 30;
    vao = createHermit(&vbo, n);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        poll_keyboard(window);

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glBindVertexArray(vao);

        glDrawArrays(GL_LINE_STRIP,0,n);

        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    glfwTerminate();
}

GLuint createHermit(GLuint* vbo, const GLuint n)
{
    Vector3 p1 = { -0.5f, 0.0f, 0.0f };
    Vector3 p2 = {  0.5f, 0.0f, 0.0f };
    Vector3 T1 = {  0.0f, 1.0f, 0.0f };
    Vector3 T2 = {  0.0f, 1.0f, 0.0f };

    GLfloat vertices[ (n + 1) * 3 ] = { };

    GLuint index = 0;

    GLfloat inc = (GLfloat) 1 / n;

    for (GLfloat i = 0; i <= 1.0f; i +=inc)
    {
        GLfloat t1 = i;
        GLfloat t2 = i*i;
        GLfloat t3 = i*i*i;

        Vector3 temp = 
            (1 - 3*t2 + 2*t3 )*p1 + (3*t2 - 2*t3 )*p2 + (t1 - 2*t2 + t3)*T1 + (-t2 + t3)*T2;
        vertices[3 * index + 0] = temp.x;
        vertices[3 * index + 1] = temp.y;
        vertices[3 * index + 2] = 0.0f;
        index++;
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