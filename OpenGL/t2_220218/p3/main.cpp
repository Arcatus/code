#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "math3d.h"

const GLuint WIDTH = 512, HEIGHT = 512;

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

    GLuint vao, ebo, vbo;
    vao = createModel(&vbo, &ebo);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    Vector3 z = { 0.0f, 0.0f, 1.0f };

    Matrix4x4 S;
    Matrix4x4MakeScaling(1.0f,0.5f,1.0f,&S);

    Matrix4x4 R;
    Matrix4x4MakeRotation(&z,45.0f,&R);

    Matrix4x4 trans1 = R * S;
    Matrix4x4 trans2 = S * R;


    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"trans1"),1,GL_TRUE,(GLfloat*)trans1.m);
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"trans2"),1,GL_TRUE,(GLfloat*)trans2.m);

        glUniform1i(glGetUniformLocation(shaderProgram, "sel"),GL_TRUE);        

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glUniform1i(glGetUniformLocation(shaderProgram, "sel"),GL_FALSE);        

        glBindVertexArray(vao);
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

GLuint createModel(GLuint* vbo, GLuint* ebo)
{
    GLfloat vertices[] = 
    {
        0.0f,0.0f,0.0f,
        0.0f,0.5f,0.0f,
        0.5f,0.5f,0.0f,
        0.5f,0.0f,0.0f,
    };

    GLuint elements[] = 
    {
        0,1,3,
        1,2,3
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
