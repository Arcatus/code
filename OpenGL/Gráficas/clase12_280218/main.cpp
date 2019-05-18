/*
    @title = Curvas y Superficies
    @Description = 
    Superficie de bezier creada mediante 16 puntos de control,
    con la posibilidad de modificar la cantidad de vertices a
    lo largo y ancho.
    @autor = arcatus
*/

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

GLuint createBezierSurface(GLuint* vbo, GLuint* ebo, GLuint resx, GLuint resz);

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
    camera.position = { 0.5f, 1.0f, 3.0f };
    camera.target   = { 0.0f, 0.0f,-1.0f };
    camera.up       = { 0.0f, 1.0f, 0.0f };
    camera.speed    = 0.1;
    camera.enable = -1;

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

    GLdouble xpos = 0.0f;
    GLdouble ypos = 0.0f;
    GLuint vao, vbo, ebo;

    GLuint resx = 16;
    GLuint resz = 16;

    vao = createBezierSurface(&vbo,&ebo,resx,resz);

    Matrix4x4 mvp, projection, model, view, rotationAxisUp, rotationAxisSide;

    Matrix4x4MakeIdentity(&model);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_DEPTH_TEST);

    Vector3 newDelta={}, oldDelta={}, current={};

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
        mvp = projection * rotationAxisUp * rotationAxisSide * view * model;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "mvp"),1, GL_TRUE, (GLfloat*)mvp.m);
 
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, resx * resz * 3 * 2, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    glfwTerminate();
}

GLuint createBezierSurface(GLuint* vbo, GLuint* ebo, GLuint resx, GLuint resz)
{
    Vector3 ControlPoints[4][4] = 
    {
        { 
            { -4.0f, 0.0f, -4.0f }, 
            { -2.0f, 0.0f, -4.0f },
            {  2.0f, 0.0f, -4.0f }, 
            {  4.0f, 0.0f, -4.0f }
        },
        {
            { -4.0f, 0.0f, -2.0f },
            { -2.0f, 5.0f, -2.0f },
            {  2.0f, 5.0f, -2.0f },
            {  4.0f, 0.0f, -2.0f }
        },
        {
            { -4.0f, 0.0f,  2.0f },
            { -2.0f, 5.0f, -2.0f },
            {  2.0f, 5.0f,  2.0f },
            {  4.0f, 0.0f,  2.0f }
        },
        {
            { -4.0f, 0.0f,  4.0f },
            { -2.0f, 0.0f,  4.0f },
            {  2.0f, 0.0f,  4.0f },
            {  4.0f, 0.0f,  4.0f }
        }
    };

    GLfloat* vertices = new GLfloat[(resx + 1) * (resz + 1) * 3]();

    GLuint index = 0;

    GLfloat inc_s = (GLfloat) 1 / resx;
    GLfloat inc_t = (GLfloat) 1 / resz;

    for(GLfloat s = 0; s <= 1; s+=inc_s)
    {
        for(GLfloat t = 0; t <= 1; t+=inc_t)
        {
            for (GLuint l = 0; l <= 3; ++l)
            for (GLuint k = 0; k <= 3; ++k)
            {
                Vector3 Qst = 
                bernstein_polynomial(k,3,s)  * 
                bernstein_polynomial (l,3,t) * ControlPoints[k][l];
                vertices[index * 3 + 0] += Qst.x;
                vertices[index * 3 + 1] += Qst.y;
                vertices[index * 3 + 2] += Qst.z;
            }
            index++;
        }
    }

    GLuint* elements  = new GLuint[resx * resz * 2 * 3];

    GLuint* el = elements;

    for (GLuint z = 0; z < resz; z++)
    {
        for (GLuint x = 0; x < resx; x++)
        {
            int e0 = (resx + 1) * z + x;
            int e1 = e0 + 1;
            int e2 = e0 + (resx + 1);
            int e3 = e2 + 1;

            *el++ = e0;
            *el++ = e2;
            *el++ = e1;
            *el++ = e1;
            *el++ = e2;
            *el++ = e3;
        }
    }

    GLuint vao;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, (resx + 1) * (resz + 1) * 3 * sizeof(GLfloat),
                 vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, resx * resz * 2 * 3 * sizeof(GLuint),
                 elements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    delete[] vertices;
    delete[] elements;

    return vao;
}

void poll_mouse(GLFWwindow* window, GLdouble* xpos, GLdouble* ypos)
{
    GLdouble xtemp, ytemp;
    glfwGetCursorPos(window,&xtemp,&ytemp);
    *xpos =  2*xtemp /  WIDTH;
    *ypos =  2*ytemp / HEIGHT;
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
