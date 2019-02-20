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

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

    Vector3 target = { 0.0f, 0.0f, 0.0f };
    glfwSetWindowUserPointer(window, (GLvoid*)&target);

    GLuint vbo, ebo;
    Body body, body2, body3, body4;

    body.vao = createModel(&vbo, &ebo);
    body2.vao = createModel(&vbo, &ebo);
    body3.vao = createModel(&vbo, &ebo);
    body4.vao = createModel(&vbo, &ebo);
    // seguir
    body.position = { -0.25f, 0.0f, 0.0f };
    body.velocity = { 0.0f, 0.0f, 0.0f };
    body.mass = 1.0f;

    body2.position = { 0.0f, 0.30f, 0.0f };
    body2.velocity = { 0.0f, 0.0f, 0.0f };
    body2.mass = 100.0f;

    // alejarse
    body3.position = { 0.0f,-0.25f, 0.0f };
    body3.velocity = { 0.0f, 0.0f, 0.0f };
    body3.mass = 10.0f;
    body4.position = { 0.25f, 0.0f, 0.0f };
    body4.velocity = { 0.0f, 0.0f, 0.0f };
    body4.mass = 50.0f;

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
            //body1
            Vector3 targetVelocity = target - body.position;
            Vector3Normalize(&targetVelocity);
            targetVelocity = 0.005 * targetVelocity;

            Vector3 steering = targetVelocity - body.velocity;
            steering = (1.0f / body.mass) * steering;

            body.velocity = body.velocity + steering;
            body.position = body.position + body.velocity;

            //body2

            Vector3 targetVelocity2 = target - body2.position;
            Vector3Normalize(&targetVelocity2);
            targetVelocity2 = 0.005 * targetVelocity2;

            Vector3 steering2 = targetVelocity2 - body2.velocity;
            steering2 = (1.0f / body2.mass) * steering2;

            body2.velocity = body2.velocity + steering2;
            body2.position = body2.position + body2.velocity;

            //body3

            Vector3 targetVelocity3 = body3.position - target;
            Vector3Normalize(&targetVelocity3);
            targetVelocity3 = 0.005 * targetVelocity3;

            Vector3 steering3 = targetVelocity3 - body3.velocity;
            steering3 = (1.0f / body3.mass) * steering3;

            body3.velocity = body3.velocity + steering3;

            if ( abs(body3.position.x) < 1 && abs(body3.position.y) < 1)
                body3.position = body3.position + body3.velocity;
            else 
                body3.position = Vector3{0.0f,0.0f,0.0f};

            //body4
            Vector3 targetVelocity4 = body4.position - target;
            Vector3Normalize(&targetVelocity4);
            targetVelocity4 = 0.005 * targetVelocity4;

            Vector3 steering4 = targetVelocity4 - body4.velocity;
            steering4 = (1.0f / body4.mass) * steering4;

            body4.velocity = body4.velocity + steering4;

            if ( abs(body4.position.x) < 1 && abs(body4.position.y) < 1)
                body4.position = body4.position + body4.velocity;
            else 
                body4.position = Vector3{0.0f,0.0f,0.0f};
            
            elapsedTime = 0.0;
        }

        Matrix4x4 scaling;
        Matrix4x4MakeScaling(0.05f, 0.05f, 0.05f, &scaling);

        Matrix4x4 translation, translation2, translation3, translation4;
        Matrix4x4MakeTranslation(body.position.x,body.position.y,body.position.z,&translation);
        Matrix4x4MakeTranslation(body2.position.x,body2.position.y,body2.position.z,&translation2);
        Matrix4x4MakeTranslation(body3.position.x,body3.position.y,body3.position.z,&translation3);
        Matrix4x4MakeTranslation(body4.position.x,body4.position.y,body4.position.z,&translation4);

        Matrix4x4 transformation  =  translation * scaling;
        Matrix4x4 transformation2 = translation2 * scaling;
        Matrix4x4 transformation3 = translation3 * scaling;
        Matrix4x4 transformation4 = translation4 * scaling;
        
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        //body1
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "transformation"),
                           1, GL_TRUE, (GLfloat*)transformation.m);
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"),0.18f, 0.81f, 0.79f, 1.0f);
        glBindVertexArray(body.vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        //body2
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "transformation"),
                           1, GL_TRUE, (GLfloat*)transformation2.m);
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"),0.89f, 0.15f, 0.78f, 1.0f);
        glBindVertexArray(body2.vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        //body3
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "transformation"),
                           1, GL_TRUE, (GLfloat*)transformation3.m);
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"),0.73f, 0.87f, 0.78f, 1.0f);
        glBindVertexArray(body3.vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        //body4
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "transformation"),
                           1, GL_TRUE, (GLfloat*)transformation4.m);
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"),0.89f, 0.17f, 0.32f, 1.0f);
        glBindVertexArray(body4.vao);
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
        -0.5f, -0.5f, 0.0f, 
         0.5f, -0.5f, 0.0f, 
        -0.5f,  0.5f, 0.0f, 
         0.5f,  0.5f, 0.0f
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

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
