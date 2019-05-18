#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "math3d.h"
#include "camera.h"
#include "body.h"
#include "texture.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);
void poll_keyboard(GLFWwindow* window, Camera* camera);
void poll_mouse(GLFWwindow* window, Camera* camera);
GLuint createPlane(GLuint* vbo, GLuint* ebo);

GLuint createGrid(GLuint* vbo, GLuint* ebo, GLuint resx, GLuint resz, GLuint numComp);

GLfloat lastX = 256, lastY = 256, yaw = -287.0f, pitch = 0.0f;

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
    camera.position = { 0.0f, 2.0f, 3.0f };
    camera.target   = { 0.0f, 0.0f,-1.0f };
    camera.up       = { 0.0f, 1.0f, 0.0f };
    camera.speed    = 0.05;
    camera.mouseInit = GL_TRUE;

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

    GLuint vao, vbo, ebo, eboPlane, vboPlane;

    GLuint resx = 8;
    GLuint resz = 8;
    GLuint numComp = 8;
    GLuint texture0 = createTextureObject("hoja.jpg");
    GLuint texture1 = createTextureObject("suelo.jpg");
    vao = createGrid(&vbo,&ebo,resx,resz,numComp);
    GLuint vaoPlane = createPlane(&vboPlane,&eboPlane);

    Matrix4x4 mvp, projection, model, view;
    glPointSize(2.0f);
    Matrix4x4MakeIdentity(&model);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
    glEnable(GL_DEPTH_TEST);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        poll_mouse(window,&camera);
        poll_keyboard(window, &camera);
        
        Vector3 newTarget = camera.position + camera.target;
        Matrix4x4MakeView(&camera.position, &newTarget, &camera.up, &view);

        Matrix4x4MakePerspective(45.0f, WIDTH / HEIGHT, 0.1f, 100.f, &projection);
        mvp = projection * view * model;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture0);
        glUniform1i(glGetUniformLocation(shaderProgram, "sampler0"), 0);

        glUniform3f(glGetUniformLocation(shaderProgram, "lightPosition"),
            camera.position.x,camera.position.y,camera.position.z);

        glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "model"),1, GL_TRUE, (GLfloat*)model.m);
        glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "mvp"),1, GL_TRUE, (GLfloat*)mvp.m);
 
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, resx * resz * 6 + resx * 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glUniform1i(glGetUniformLocation(shaderProgram, "sampler0"), 1);

        glBindVertexArray(vaoPlane);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vaoPlane);
    glDeleteBuffers(1, &vboPlane);

    glfwTerminate();
}

GLuint createGrid(GLuint* vbo, GLuint* ebo, GLuint resx, GLuint resz,GLuint numComp)
{
    GLfloat* vertices = new GLfloat[(resx + 1) * (resz + 1) * numComp]();
    GLuint* elements  = new GLuint[resx * resz * 3 * 2 + resx * 6]();

    GLfloat r = 0.5f;

    GLfloat* v = vertices;

    for(GLuint z = 0; z <= resz; z++)
    {
        for(GLuint x = 0; x <= resx; x++)
        {
            GLfloat s = x / (GLfloat)(resx);
            GLfloat t = z / (GLfloat)(resz);

            *v++ = r * cos(2*M_PI*s);
            *v++ = z / resz;
            *v++ = r * sin(2*M_PI*s);
            // skip normals
            v+= 3;
            //texture
            *v++ = s;
            *v++ = t;
        }
    }

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
    //bottom
    for(GLuint i = 0; i < resx ; i++) {
        *el++ = 0;
        *el++ = i + 1;
        *el++ = i + 2;
    }
    //top
    for(GLuint i = 0 ; i < resx; i++) {
        *el++ = resx*10 ;
        *el++ = resx*10 - i;
        *el++ = resx*10 - i - 1;
    }

    calcNormals(elements, resx * resz * 6 + resx * 6 , vertices, (resx + 1) * (resz + 1), numComp);

    GLuint vao;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, (resx + 1) * (resz + 1) * numComp * sizeof(GLfloat),
                 vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, resx * resz * 6 * sizeof(GLuint) 
        + resx * 6 * sizeof(GLuint), elements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, numComp * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, numComp * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, numComp * sizeof(GLfloat), (GLvoid*)(6*sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    delete[] vertices;
    delete[] elements;

    return vao;
}

GLuint createPlane(GLuint* vbo, GLuint* ebo)
{
    GLfloat vertices[] =
    {
        -3.0f,0.0f, -3.0f,     0.0f, 1.0f, 0.0f,    0.0f, 0.0f,
        -3.0f,0.0f,  3.0f,     0.0f, 1.0f, 0.0f,    0.1f, 0.0f,
         3.0f,0.0f, -3.0f,     0.0f, 1.0f, 0.0f,    0.0f, 0.1f,
         3.0f,0.0f,  3.0f,     0.0f, 1.0f, 0.0f,    0.1f, 0.1f
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
                 vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements),
                 elements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

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
        camera->position.y+=0.05;
    }

    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        camera->position.y-=0.05;
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
