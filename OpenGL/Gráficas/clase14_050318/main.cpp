#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "math3d.h"
#include "camera.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);
void poll_keyboard(GLFWwindow* window, Camera* camera);
void poll_mouse(GLFWwindow* window, GLdouble* xpos, GLdouble* ypos);

GLuint createModel(GLuint* vbo, GLuint* ebo);
GLuint createPlane(GLuint* vbo, GLuint* ebo);
void CalcNormals(GLfloat* vertices, GLuint numVertices, GLuint* elements, GLuint numElements);

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

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "Error: " << glewGetErrorString(status) << std::endl;

        return 1;
    }

    Camera camera;
    camera.position = { 0.0f, 0.8f, 5.0f };
    camera.target   = { 0.0f, 0.0f,-1.0f };
    camera.up       = { 0.0f, 1.0f, 0.0f };
    camera.speed    = 0.15;
    camera.enable = -1;

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

    GLdouble xpos = 0.0f, ypos = 0.0f;

    GLuint vao[2], vbo[2], ebo[2];

    vao[0] = createPlane(&vbo[0],&ebo[0]);
    vao[1] = createModel(&vbo[1],&ebo[1]);

    Matrix4x4 mvp, projection, model, view, rotationAxisUp, rotationAxisSide;

    Matrix4x4MakeIdentity(&model);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);

    Vector3 newDelta = { };
    Vector3 oldDelta = { };
    Vector3  current = { };

    GLfloat currentTime = 0.0f;
    GLfloat t = 0.0f;
    GLfloat oldTime = 0.0f;

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        poll_keyboard(window, &camera);
        poll_mouse(window,&xpos,&ypos);
        current  = { float(xpos), float(ypos), 0.0f };

        switch(camera.enable)
        {
            case  0: newDelta  = current - oldDelta; break;
            case -1: oldDelta  = current;
        }

        Vector3 newTarget = camera.position + camera.target;

        Vector3 s = Matrix4x4MakeView(&camera.position, &newTarget, &camera.up, &view);

        Matrix4x4MakeRotation(&camera.up,newDelta.x,&rotationAxisUp);
        Matrix4x4MakeRotation(&s,newDelta.y,&rotationAxisSide);

        Matrix4x4MakePerspective(45.0f, WIDTH / HEIGHT, 0.1f, 100.f, &projection);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        currentTime = (GLfloat)glfwGetTime();
        t += currentTime - oldTime;
        oldTime = currentTime;

        Vector3 light = { 2.0f * cosf(t), 1.5f, 2.0f * sinf(t) };

        glUseProgram(shaderProgram);

        glUniform3f(
            glGetUniformLocation(shaderProgram, "lightPosition"),light.x,light.y,light.z);

        glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "model"),1, GL_TRUE, (GLfloat*)model.m);

        mvp = projection * rotationAxisUp * rotationAxisSide * view * model;

        glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "mvp"),1, GL_TRUE, (GLfloat*)mvp.m);

        glBindVertexArray(vao[1]);
        glDrawElements(GL_TRIANGLES,12, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glBindVertexArray(vao[0]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, vao);
    glDeleteBuffers(1, vbo);
    glDeleteBuffers(1, ebo);

    glfwTerminate();
}

GLuint createPlane(GLuint* vbo, GLuint* ebo)
{
    GLfloat vertices[] =
    {
        -3.0f,-0.51f, -3.0f,     0.0f, 0.1f, 0.4f, 1.0f,     0.0f, 1.0f, 0.0f,
        -3.0f,-0.51f,  3.0f,     0.0f, 0.1f, 0.4f, 1.0f,     0.0f, 1.0f, 0.0f,
         3.0f,-0.51f, -3.0f,     0.0f, 0.1f, 0.4f, 1.0f,     0.0f, 1.0f, 0.0f,
         3.0f,-0.51f,  3.0f,     0.0f, 0.1f, 0.4f, 1.0f,     0.0f, 1.0f, 0.0f,
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(GLfloat), (GLvoid*)(7 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return vao;
}

GLuint createModel(GLuint* vbo, GLuint* ebo)
{
    GLfloat vertices[] =
    {
         -0.5f, -0.5f,   0.5f,   1.0f, 0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f, // 0
          0.0f,  0.5f,   0.0f,   1.0f, 0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f, // 1
          0.0f, -0.5f,  -0.5f,   1.0f, 0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f, // 2
          0.5f, -0.5f,   0.5f,   1.0f, 0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f  // 3
    };

    GLuint elements[] =
    {
        2,0,1,
        0,3,1,
        3,2,1,
        3,0,2
    };

    CalcNormals(vertices,4,elements,12);

    GLuint vao;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                          10 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
                          10 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE,
                          10 * sizeof(GLfloat), (GLvoid*)(7 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return vao;
}

void CalcNormals(GLfloat* vertices, GLuint numVertices, GLuint* elements, GLuint numElements)
{
    for (GLuint i = 0; i < numElements; i+=3)
    {
        GLuint e0 = elements[i];
        GLuint e2 = elements[i+1];
        GLuint e1 = elements[i+2];
        Vector3 a;
        a.x = vertices[10*e0] - vertices[10*e2];
        a.y = vertices[10*e0+1] - vertices[10*e2+1];
        a.z = vertices[10*e0+2] - vertices[10*e2+2];
        Vector3 b;
        b.x = vertices[10*e1] - vertices[10*e2];
        b.y = vertices[10*e1+1] - vertices[10*e2+1];
        b.z = vertices[10*e1+2] - vertices[10*e2+2];

        Vector3 normal;
        Vector3CrossProduct(&b,&a,&normal);
        Vector3Normalize(&normal);
                
        vertices[10*e0 + 7] += normal.x;
        vertices[10*e0 + 8] += normal.y;
        vertices[10*e0 + 9] += normal.z;

        vertices[10*e1 + 7] += normal.x;
        vertices[10*e1 + 8] += normal.y;
        vertices[10*e1 + 9] += normal.z;

        vertices[10*e2 + 7] += normal.x;
        vertices[10*e2 + 8] += normal.y;
        vertices[10*e2 + 9] += normal.z;
    }
}


void poll_mouse(GLFWwindow* window, GLdouble* xpos, GLdouble* ypos)
{
    GLdouble xtemp, ytemp;
    glfwGetCursorPos(window,&xtemp,&ytemp);
    *xpos =  2 * xtemp /  WIDTH;
    *ypos =  2 * ytemp / HEIGHT;
}

void poll_keyboard(GLFWwindow* window, Camera* camera)
{
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        camera->enable =  0;
    }

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
    {
        camera->enable = -1;
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

void error_callback(GLint error, const GLchar* description)
{
    std::cerr << "Error " << error << ": " << description << std::endl;

    exit(1);
}
