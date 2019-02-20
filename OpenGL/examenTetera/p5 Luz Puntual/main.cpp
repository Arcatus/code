
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <limits>

#include "shader_util.h"
#include "math3d.h"
#include "camera.h"
#include "body.h"

const GLuint WIDTH = 512, HEIGHT = 512;

std::ifstream& GotoLine(std::ifstream& file, GLuint num){
    file.seekg(std::ios::beg);
    for(int i = 0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

void error_callback(GLint error, const GLchar* description);
void poll_keyboard(GLFWwindow* window, Camera* camera);
void poll_mouse(GLFWwindow* window, Camera* camera);

GLuint createTeteraUtah
    (GLuint* vbo, GLuint* ebo, GLuint resx, GLuint resz, GLuint numcomp, GLuint bezierLayer);

GLfloat lastX = 256, lastY = 256, yaw = -290.0f, pitch = 0.0f;

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
    glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "Error: " << glewGetErrorString(status) << std::endl;

        return 1;
    }

    Camera camera;
    camera.position = { 0.5f, 1.5f, 7.0f };
    camera.target   = { 0.0f, 0.0f,-1.0f };
    camera.up       = { 0.0f, 1.0f, 0.0f };
    camera.speed    = 0.03;
    camera.mouseInit = GL_TRUE;

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

    GLuint vao, vbo, ebo;

    GLuint resx = 16;
    GLuint resz = 16;
    GLuint numcomp = 8;
    GLuint bezierLayer = 32;
    vao = createTeteraUtah(&vbo,&ebo,resx,resz,numcomp,bezierLayer);

    Matrix4x4 mvp, projection, model, view;

    Matrix4x4MakeIdentity(&model);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);

    GLfloat currentTime = 0.0f;
    GLfloat elapsedTime = 0.0f;
    GLfloat oldTime = 0.0f;

    Vector3 AxisX = { 1.0f,0.0f,0.0f };

    while(!glfwWindowShouldClose(window))
    {        
        currentTime = (GLfloat) glfwGetTime();
        elapsedTime += currentTime - oldTime;
        oldTime = currentTime;

        glfwPollEvents();
        poll_keyboard(window, &camera);
        poll_mouse(window,&camera);

        Vector3 newTarget = camera.position + camera.target;
        Matrix4x4MakeView(&camera.position, &newTarget, &camera.up, &view);

        Matrix4x4MakePerspective(45.0f, WIDTH / HEIGHT, 0.1f, 100.f, &projection);

        Matrix4x4MakeRotation(&AxisX,4.75,&model);

        mvp = projection * view * model;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glUniform3f(
            glGetUniformLocation(shaderProgram, "lightPosition"),
             10.0f*sin(elapsedTime),10.0f*cosf(elapsedTime),3.5f);

        glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "model"),1, GL_TRUE, (GLfloat*)model.m);

        glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "mvp"),1, GL_TRUE, (GLfloat*)mvp.m);

        glBindVertexArray(vao);
        glDrawElements(
            GL_TRIANGLES, (resx * resz * 3 * 2) * bezierLayer, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    glfwTerminate();
}

GLuint createTeteraUtah
    (GLuint* vbo, GLuint* ebo, GLuint resx, GLuint resz, GLuint numcomp, GLuint bezierLayer)
{

    Vector3 controlPoints[16*bezierLayer] = { };

    std::ifstream iFile("cp_indices.txt",std::ios::in);
    std::ifstream pFile("control_points.txt",std::ios::in);
    std::ifstream bFile("bottom.txt",std::ios::in);

    unsigned int control;
    GLfloat getx, gety, getz;

    for (int bezier = 0; bezier < bezierLayer; bezier++)
    {
        if(bezier < 28)
        {
            for (int i = 0; i < 16; i++)
            {
                iFile >> control;
                GotoLine(pFile, control);
                pFile >> getx >> gety >> getz;
                controlPoints[bezier * 16 + i] = Vector3{ getx, gety, getz };
            }
        } else  {
            for (int i = 0; i < 16; i++)
            {
                bFile >> getx >> gety >> getz;
                controlPoints[bezier * 16 + i] = Vector3{ getx, gety, getz };
            }
        }
    }

    GLuint index = 0;

    GLfloat* vertices = new GLfloat[((resx + 1) * (resz + 1) * numcomp) * bezierLayer]();

    for (int i = 0; i < bezierLayer; ++i)
    {
        for(GLuint z = 0; z <= resz; z++)
        {
            for(GLuint x = 0; x <= resx; x++)
            {
                GLfloat s = x / (GLfloat)(resx);
                GLfloat t = z / (GLfloat)(resz);

                for (GLuint k = 0; k <= 3; ++k)
                for (GLuint l = 0; l <= 3; ++l)
                {
                    Vector3 Qst = 
                    bernstein_polynomial(k,3,s)  * 
                    bernstein_polynomial (l,3,t) * controlPoints[k*4 + l + (i*16)];

                    vertices[index * numcomp + 0] +=  Qst.x;
                    vertices[index * numcomp + 1] +=  Qst.y;
                    vertices[index * numcomp + 2] +=  Qst.z;
                }
                vertices[index * numcomp + 6] =  s;
                vertices[index * numcomp + 7] =  t;
                index++;
            }
        }
    }

    GLuint* elements  = new GLuint[(resx * resz * 2 * 3) * bezierLayer];

    GLuint* el = elements;

    for (GLuint w = 0; w < bezierLayer; w++)
    {
        for (GLuint z = 0; z < resz ; z++)
        {
            for (GLuint x = 0; x < resx ; x++)
            {
                int e0 = (resx + 1 ) * z + x;
                int e1 = e0 + 1;
                int e2 = e0 + (resx + 1);
                int e3 = e2 + 1;
                *el++ = e0 + (resx + 1) * (resz + 1) * w;
                *el++ = e2 + (resx + 1) * (resz + 1) * w;
                *el++ = e1 + (resx + 1) * (resz + 1) * w;
                *el++ = e1 + (resx + 1) * (resz + 1) * w;
                *el++ = e2 + (resx + 1) * (resz + 1) * w;
                *el++ = e3 + (resx + 1) * (resz + 1) * w;
            }
        }
    }
    
    calcNormals(elements, (resx * resz * 2 * 3) 
        * bezierLayer, vertices, (resx + 1) * (resz + 1) * bezierLayer, numcomp);

    GLuint vao;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, ((resx + 1) * (resz + 1) * numcomp)* bezierLayer * sizeof(GLfloat),
                 vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (resx * resz * 2 * 3) * bezierLayer * sizeof(GLuint),
                 elements, GL_STATIC_DRAW);

    // posicion
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // normal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    // textura
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6*sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

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

    if (pitch > 60.0f)
        pitch = 60.0f;
    if (pitch < -60.0f)
        pitch = -60.0f;

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
        camera->position.y+=0.02;
    }

    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        camera->position.y-=0.02;
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
