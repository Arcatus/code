
#include <iostream>
#include <fstream>
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
void poll_mouse(GLFWwindow* window, Camera* camera);

GLuint createTeteraUtah(GLuint*, GLuint*, GLuint, GLuint, GLuint);

GLfloat lastX = 256, lastY = 256, yaw = -287.0f, pitch = 0.0f;

int main()
{
    std::ios_base::sync_with_stdio(false);

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
    glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "Error: " << glewGetErrorString(status) << std::endl;

        return 1;
    }

    Camera camera;
    camera.position = { 0.0f, 1.0f, 3.0f };
    camera.target   = { 0.0f, 0.0f,-1.0f };
    camera.up       = { 0.0f, 1.0f, 0.0f };
    camera.speed    = 0.1;
    camera.mouseInit = GL_TRUE;

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

    GLuint vao, vbo, ebo;

    GLuint resx = 32;
    GLuint resz = 32;
    GLuint numcomp = 7;

    vao = createTeteraUtah(&vbo,&ebo,resx,resz,numcomp);

    Matrix4x4 mvp, projection, model, view;

    Matrix4x4MakeIdentity(&model);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_DEPTH_TEST);

    glPointSize(1.0f);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        poll_keyboard(window, &camera);
        poll_mouse(window,&camera);

        Vector3 newTarget = camera.position + camera.target;
        Matrix4x4MakeView(&camera.position, &newTarget, &camera.up, &view);

        Matrix4x4MakePerspective(45.0f, WIDTH / HEIGHT, 0.1f, 100.f, &projection);

        mvp = projection * view * model;

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

GLuint createTeteraUtah(GLuint* vbo, GLuint* ebo, GLuint resx, GLuint resz, GLuint numcomp)
{

    Vector3 controlPoints[4][4] = { };

    std::ifstream file("control_points.txt");

    GLfloat getx, gety, getz;
    GLuint i = 0;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            file >> getx >> gety >> getz;
            controlPoints[i][j] = Vector3{ getx, gety, getz };
        }
    }
    
    GLfloat* vertices = new GLfloat[(resx + 1) * (resz + 1) * numcomp]();

    GLuint index = 0;

    GLfloat inc_s = (GLfloat) 1 / resx;
    GLfloat inc_t = (GLfloat) 1 / resz;

    auto colorea = []() {
        return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    };

    for(GLfloat s = 0; s <= 1; s+=inc_s)
    {
        for(GLfloat t = 0; t <= 1; t+=inc_t)
        {
            for (GLuint k = 0; k <= 3; ++k)
            for (GLuint l = 0; l <= 3; ++l)
            {
                Vector3 Qst = 
                bernstein_polynomial(k,3,s)  * 
                bernstein_polynomial (l,3,t) * controlPoints[k][l];
                vertices[index * numcomp + 0] +=  Qst.x;
                vertices[index * numcomp + 1] +=  Qst.y;
                vertices[index * numcomp + 2] +=  Qst.z;
            }
            vertices[index * numcomp + 3] =  colorea();
            vertices[index * numcomp + 4] =  colorea();
            vertices[index * numcomp + 5] =  colorea();
            vertices[index * numcomp + 6] =  1.0f;
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
    glBufferData(GL_ARRAY_BUFFER, (resx + 1) * (resz + 1) * numcomp * sizeof(GLfloat), vertices, GL_STATIC_DRAW);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, resx * resz * 2 * 3 * sizeof(GLuint),
                 elements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    delete[] vertices;
    delete[] elements;

    return vao;
}

void poll_mouse(GLFWwindow* window, Camera* camera)
{
    GLdouble xpos, ypos;
    glfwGetCursorPos(window,&xpos,&ypos);

    if (camera->mouseInit)
    {
        lastX = xpos;
        lastY = ypos;
        camera->mouseInit = GL_FALSE;
    }    

    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = ypos - lastY;
    lastX = xpos;
    lastY = ypos;

    GLfloat sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   += xoffset;
    pitch += yoffset;

    if (pitch > 45.0f)
        pitch = 45.0f;
    if (pitch < -45.0f)
        pitch = -45.0f;

    Vector3 newTarget;
    newTarget.x = cos(yaw/180) * cos(pitch/180);
    newTarget.y = sin(pitch/180);
    newTarget.z = sin(yaw/180) * cos(pitch/180);

    camera->target = Vector3Normalize(newTarget);
}

void poll_keyboard(GLFWwindow* window, Camera* camera)
{
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        camera->position.y+=0.1;
    }

    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        camera->position.y-=0.1;
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
