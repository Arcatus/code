#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "math3d.h"
#include "body.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);
void cursor_pos_callback(GLFWwindow* window, GLdouble mouseX, GLdouble mouseY);

GLuint createModel(GLuint* vbo, GLuint* ebo);

int main()
{
    glfwSetErrorCallback(error_callback);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGLApp",
                                          NULL, NULL);

    if(!window)
    {
        std::cerr << "Error: can't create GLFW window." << std::endl;

        return 1;
    }

    glfwMakeContextCurrent(window);

    glfwSetCursorPosCallback(window, cursor_pos_callback);

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "Error: " << glewGetErrorString(status) << std::endl;

        return 1;
    }

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl",
                                             "fragment_shader.glsl");

    Vector3 target = { 0.0f, 0.0f, 0.0f };
    glfwSetWindowUserPointer(window, (GLvoid*)&target);

    GLuint vbo, ebo;
    Body body;
    body.vao = createModel(&vbo, &ebo);
    body.position = { -1.0f, -1.0f, 0.0f };
    body.velocity = { 0.0f, 0.0f, 0.0f };
    body.mass = 200.0f;

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    GLfloat currentTime = 0.0f;
    GLfloat elapsedTime = 0.0f;
    GLfloat oldTime     = 0.0f;

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        currentTime = (GLfloat)glfwGetTime();
        elapsedTime += currentTime - oldTime;
        oldTime     = currentTime;

        if(elapsedTime > 0.016f)
        {
            Vector3 targetVelocity = target - body.position;
            Vector3Normalize(&targetVelocity);
            targetVelocity = 0.005 * targetVelocity;

            Vector3 steering = targetVelocity - body.velocity;
            steering = (1.0f / body.mass) * steering;

            body.velocity = body.velocity + steering;
            body.position = body.position + body.velocity;

            elapsedTime = 0.0;
        }

        Matrix4x4 scaling;
        Matrix4x4MakeScaling(0.05f, 0.05f, 0.05f, &scaling);

        Matrix4x4 translation;
        Matrix4x4MakeTranslation(body.position.x,
                                 body.position.y,
                                 body.position.z,
                                 &translation);

        Matrix4x4 transformation = translation * scaling;
        
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "transformation"),
                           1, GL_TRUE, (GLfloat*)transformation.m);

        glBindVertexArray(body.vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &body.vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);

    glfwTerminate();

    return 0;
}

void error_callback(GLint error, const GLchar* description)
{
    std::cerr << "Error " << error << ": " << description << std::endl;

    exit(1);
}

GLuint createModel(GLuint* vbo, GLuint* ebo)
{
    GLfloat vertices[] =
    {
        // Posicion         // Color
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
         0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    };

    GLuint elements[] =
    {
        0, 1, 2,
        1, 2, 3
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return vao;
}

void cursor_pos_callback(GLFWwindow* window, GLdouble mouseX, GLdouble mouseY)
{
    Vector3* target = (Vector3*)glfwGetWindowUserPointer(window);

    target->x =  2.0f * mouseX / WIDTH  - 1;
    target->y = -2.0f * mouseY / HEIGHT + 1;
    target->z =  0.0f;
}
