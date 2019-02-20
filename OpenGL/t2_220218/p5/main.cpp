#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "math3d.h"
#include "camera.h"
#include "body.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);
void poll_keyboard(GLFWwindow* window, Camera* camera);
void poll_mouse(GLFWwindow* window, GLdouble* xpos, GLdouble* ypos);

GLuint createModel(GLuint* vbo, GLuint* ebo);

int main()
{
    glfwSetErrorCallback(error_callback);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGLApp", NULL, NULL);

    if(!window)
    {
        std::cerr << "Error: can't create GLFW window." << std::endl;

        return 1;
    }

    glfwMakeContextCurrent(window);

//  glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "Error: " << glewGetErrorString(status) << std::endl;

        return 1;
    }

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

    GLdouble xpos, ypos;
    GLuint vao, vbo, ebo;

    Body body;
    
    body.vao = createModel(&vbo, &ebo);
    body.position = { 0.0f, 0.0f, -1.8f };
    body.velocity = { 0.0f, 0.0f, 0.0f };
    body.mass = 200.0f;

    Camera camera;
    camera.position = { 0.0f, 0.0f, 3.0f };
    camera.target   = { 0.0f, 0.0f,-1.0f };
    camera.up       = { 0.0f, 1.0f, 0.0f };
    camera.speed    = 0.1f;
    camera.enable   = false;

    Matrix4x4 model, view;
    Matrix4x4MakeIdentity(&model);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    GLfloat currentTime = 0.0f;
    GLfloat elapsedTime = 0.0f;
    GLfloat oldTime     = 0.0f;

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnable(GL_DEPTH_TEST);

    Vector3 newDelta = { };
    Vector3 oldDelta = { };

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        poll_keyboard(window, &camera);
        poll_mouse(window,&xpos,&ypos);

        Vector3 current  = { float(xpos), float(ypos), 0.0f };

        if(camera.enable) 
            newDelta  = current - oldDelta; 
        else 
            oldDelta  = current;
        
        Vector3 newTarget = camera.position + camera.target;

        Matrix4x4 rotationAxisUp, rotationAxisSide;

        Matrix4x4MakeRotation(&camera.up,newDelta.x,&rotationAxisUp);

        Vector3 s = Matrix4x4MakeView(&camera.position, &newTarget, &camera.up, &view);

        Matrix4x4MakeRotation(&s,newDelta.y,&rotationAxisSide);

        Matrix4x4 projection;
        Matrix4x4MakePerspective(45.0f, WIDTH / HEIGHT, 0.1f, 100.f, &projection);

        currentTime = (GLfloat)glfwGetTime();
        elapsedTime += currentTime - oldTime;
        oldTime     = currentTime;

        if(elapsedTime > 0.016f)
        {
            Vector3 targetVelocity = camera.position - body.position;

            Vector3Normalize(&targetVelocity);
            targetVelocity = 0.01f  * targetVelocity;

            Vector3 steering = targetVelocity - body.velocity;
            steering = (1.0f / body.mass) * steering;

            body.velocity = body.velocity + steering;
            body.position = body.position + body.velocity;
            elapsedTime = 0.0;
        }

        Matrix4x4 translation;
        Matrix4x4MakeTranslation(body.position.x,body.position.y,body.position.z,&translation);

        Matrix4x4 mvp;
        mvp = projection * translation * rotationAxisUp * rotationAxisSide * view * model;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "mvp"),
                           1, GL_TRUE, (GLfloat*)mvp.m);
 
        glBindVertexArray(body.vao);
        glDrawElements(GL_TRIANGLES, 60, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    glfwTerminate();
}

void poll_mouse(GLFWwindow* window, GLdouble* xpos, GLdouble* ypos)
{
    GLdouble xtemp, ytemp;
    glfwGetCursorPos(window,&xtemp,&ytemp);
    *xpos = 2* xtemp / WIDTH ;
    *ypos = 2* ytemp / HEIGHT;
}

void poll_keyboard(GLFWwindow* window, Camera* camera)
{
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        camera->enable = true;
    }

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
    {
        camera->enable = false;
    }

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        Vector3 sideVector;
        Vector3CrossProduct(&camera->target, &camera->up, &sideVector);
        Vector3Normalize(&sideVector);

        camera->position = camera->position - camera->speed * sideVector;
    }

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        Vector3 sideVector;
        Vector3CrossProduct(&camera->target, &camera->up, &sideVector);
        Vector3Normalize(&sideVector);

        camera->position = camera->position + camera->speed * sideVector;
    }

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera->position = camera->position + camera->speed * camera->target;
    }

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera->position = camera->position - camera->speed * camera->target;
    }
}

GLuint createModel(GLuint* vbo, GLuint* ebo)
{
    GLfloat vertices[] =
    {
        // Top vertices
         1.0f,   1.618f, 0.0f,         1.0f, 0.0f, 0.0f, 1.0f,
        -1.0f,   1.618f, 0.0f,         1.0f, 1.0f, 0.0f, 1.0f,
         0.0f,   1.0f,   1.618f,       0.0f, 0.0f, 1.0f, 1.0f,
         1.618f, 0.0f,   1.0f,         0.0f, 1.0f, 1.0f, 1.0f,
         1.618f, 0.0f,  -1.0f,         0.0f, 0.0f, 1.0f, 1.0f,
         0.0f,   1.0f,  -1.618f,       1.0f, 0.0f, 0.0f, 1.0f,

        // Bottom vertices
        -1.0f,  -1.618f, 0.0f,         1.0f, 0.0f, 0.0f, 1.0f,
        -1.618f, 0.0f,   1.0f,         1.0f, 0.0f, 1.0f, 1.0f, 
         0.0f,  -1.0f,   1.618f,       0.0f, 0.0f, 1.0f, 1.0f,
         1.0f,  -1.618f, 0.0f,         0.0f, 1.0f, 1.0f, 1.0f,
         0.0f,  -1.0f,  -1.618f,       1.0f, 1.0f, 0.0f, 1.0f,
        -1.618f, 0.0f,  -1.0f,         1.0f, 0.0f, 1.0f, 1.0f, 
    };

    GLuint elements[] =
    {
        // Top
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 1,
        // Mid
        1, 7, 2, 2, 7, 8,
        2, 8, 3, 3, 8, 9,
        3, 9, 4, 4, 9, 10,
        4, 10, 5, 5, 10, 11,
        5, 11, 1, 1, 11, 7,
        // Bottom
        6, 8, 7,
        6, 9, 8,
        6, 10, 9,
        6, 11, 10,
        6, 7, 11
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

void error_callback(GLint error, const GLchar* description)
{
    std::cerr << "Error " << error << ": " << description << std::endl;

    exit(1);
}
