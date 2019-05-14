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

GLuint crearHermit(GLuint* vbo, GLuint* ebo, GLuint n);

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
    glPointSize(5.0f);

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

    GLuint vao, vbo, ebo, n = 15;
    vao = crearHermit(&vbo,&ebo, n);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        poll_keyboard(window);

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glBindVertexArray(vao);
        glDrawArrays(GL_POINTS,0,n+1+3);
        glDrawArrays(GL_LINE_STRIP,0,n);
        glDrawElements(GL_LINES,6,GL_UNSIGNED_INT,(GLvoid*)0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);

    glfwTerminate();
}

GLuint crearHermit(GLuint* vbo, GLuint* ebo, GLuint n)
{

    GLfloat vertices[ (n + 1) * 3 + 12 ] = { };
    
    GLuint index = 0;

    GLfloat inc = (GLfloat) 1 / n;

    Vector3 T1 = {  0.0f, 1.0f, 0.0f }; 
    Vector3 T2 = {  0.0f, 1.0f, 0.0f };
    Vector3 p1 = { -0.5f, 0.0f, 0.0f };
    Vector3 p4 = {  1.0f,-1.0f, 0.0f };

    Vector3 p2 =  1.0f/3.0f * T1 + p1;
    Vector3 p3 = -1.0f/3.0f * T2 + p4;

    Matrix4x4 G = {
         p1.x, p4.x, T1.x, T1.x,
         p1.y, p4.y, T1.y, T2.y,
         0.0f, 0.0f, 0.0f, 0.0f,
         0.0f, 0.0f, 0.0f, 0.0f,
    };

    Matrix4x4 MH = {
         1.0f, 0.0f,-3.0f, 2.0f, 
         0.0f, 0.0f, 3.0f,-2.0f,
         0.0f, 1.0f,-2.0f, 1.0f,
         0.0f, 0.0f,-1.0f, 1.0f,
    };

    Matrix4x4 Ht = G * MH;    

    Matrix4x4 parametrizacion;
    Matrix4x4InitToZero(&parametrizacion);

    parametrizacion.m[0][0] = 1.0f;

    for (GLfloat i = 0; i <= 1.0f; i +=inc)
    {
        parametrizacion.m[1][0] = i;
        parametrizacion.m[2][0] = i*i;
        parametrizacion.m[3][0] = i*i*i;

        Matrix4x4 tmp = Ht * parametrizacion;

        vertices[3 * index + 0] = tmp.m[0][0];
        vertices[3 * index + 1] = tmp.m[1][0];
        index++;
    }

    vertices[3*index] = p1.x; vertices[3*index+1] = p1.y; index++;
    vertices[3*index] = p2.x; vertices[3*index+1] = p2.y; index++;
    vertices[3*index] = p3.x; vertices[3*index+1] = p3.y; index++;
    vertices[3*index] = p4.x; vertices[3*index+1] = p4.y;

    GLuint elements[] = 
    {
        index-3,index-2,
        index-2,index-1,
        index-1,index+0,
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

    glBindBuffer(GL_ARRAY_BUFFER,0);

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