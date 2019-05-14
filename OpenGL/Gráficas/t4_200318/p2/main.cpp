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
void poll_mouse(GLFWwindow* window, Camera* camera);

GLuint createModel(GLuint* vbo);
GLuint createPlane(GLuint* vbo, GLuint* ebo);
GLuint createPoints(GLuint* vbo, GLfloat* p);

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
    camera.position = { 0.0f, 0.5f, 3.0f };
    camera.target   = { 0.0f, 0.0f,-1.0f };
    camera.up       = { 0.0f, 1.0f, 0.0f };
    camera.speed    = 0.15;
    camera.mouseInit = GL_TRUE;

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

    GLdouble xpos = 0.0f, ypos = 0.0f;

    GLuint vao[3], vbo[3], ebo;

    GLfloat p[] =
    {
        -3.0f, 0.5f, -3.0f,
        -3.0f, 0.5f,  3.0f,
         3.0f, 0.5f, -3.0f,
         3.0f, 0.5f,  3.0f
    };

    vao[0] = createPlane(&vbo[0],&ebo);
    vao[1] = createModel(&vbo[1]);
    vao[2] = createPoints(&vbo[2],p);

    Matrix4x4 mvp, projection, model, view;

    Matrix4x4MakeIdentity(&model);

    glPointSize(10);    
    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
    

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        poll_mouse(window,&camera);
        poll_keyboard(window,&camera);

        Vector3 newTarget = camera.position + camera.target;
        Matrix4x4MakeView(&camera.position, &newTarget, &camera.up, &view);

        Matrix4x4MakePerspective(45.0f, WIDTH / HEIGHT, 0.1f, 100.f, &projection);

        mvp = projection * view * model;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glUseProgram(shaderProgram);

        glUniform3f(glGetUniformLocation(shaderProgram, "lightPosition0"),p[0],p[1],p[2]);
        glUniform3f(glGetUniformLocation(shaderProgram, "lightPosition1"),p[3],p[4],p[5]);
        glUniform3f(glGetUniformLocation(shaderProgram, "lightPosition2"),p[6],p[7],p[8]);
        glUniform3f(glGetUniformLocation(shaderProgram, "lightPosition3"),p[9],p[10],p[11]);

        glUniform3f(
            glGetUniformLocation(shaderProgram, "viewerPosition"),
            camera.position.x,camera.position.y,camera.position.z);

        glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "model"),1, GL_TRUE, (GLfloat*)model.m);

        glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "mvp"),1, GL_TRUE, (GLfloat*)mvp.m);

        glBindVertexArray(vao[2]);
        glDrawArrays(GL_POINTS,0,4);
        glBindVertexArray(0);        

        glBindVertexArray(vao[1]);
        glDrawArrays(GL_TRIANGLES,0,12);
        glBindVertexArray(0);

        glBindVertexArray(vao[0]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, vao);
    glDeleteBuffers(1, vbo);
    glDeleteBuffers(1, &ebo);

    glfwTerminate();
}

GLuint createPoints(GLuint* vbo, GLfloat* p)
{
    GLfloat vertices[] = 
    {
        p[0],p[1],p[2],   0.0f, 1.0f, 1.0f, 1.0f,
        p[3],p[4],p[5],   0.0f, 1.0f, 1.0f, 1.0f,
        p[6],p[7],p[8],   0.0f, 1.0f, 1.0f, 1.0f,
        p[9],p[10],p[11], 0.0f, 1.0f, 1.0f, 1.0f
    };

    GLuint vao;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return vao;
}

GLuint createPlane(GLuint* vbo, GLuint* ebo)
{
    GLfloat vertices[] =
    {
        -3.0f,-0.51f, -3.0f,     0.1f, 0.2f, 0.4f, 1.0f,     0.0f, 1.0f, 0.0f,
        -3.0f,-0.51f,  3.0f,     0.1f, 0.2f, 0.4f, 1.0f,     0.0f, 1.0f, 0.0f,
         3.0f,-0.51f, -3.0f,     0.1f, 0.2f, 0.4f, 1.0f,     0.0f, 1.0f, 0.0f,
         3.0f,-0.51f,  3.0f,     0.1f, 0.2f, 0.4f, 1.0f,     0.0f, 1.0f, 0.0f,
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

GLuint createModel(GLuint* vbo)
{
    GLfloat vertices[] =
    {
        // Left
         -0.5f, -0.5f,   0.5f,   0.3f, 0.1f, 0.3f, 1.0f,   -1.0f, 0.25f, -0.5f,
          0.0f,  0.5f,   0.0f,   0.3f, 0.1f, 0.3f, 1.0f,   -1.0f, 0.25f, -0.5f,
          0.0f, -0.5f,  -0.5f,   0.3f, 0.1f, 0.3f, 1.0f,   -1.0f, 0.25f, -0.5f,

        // Right
          0.0f, -0.5f,  -0.5f,   0.1f, 0.3f, 0.3f, 1.0f,    1.0f, 0.25f, -0.5f,
          0.0f,  0.5f,   0.0f,   0.1f, 0.3f, 0.3f, 1.0f,    1.0f, 0.25f, -0.5f,
          0.5f, -0.5f,   0.5f,   0.1f, 0.3f, 0.3f, 1.0f,    1.0f, 0.25f, -0.5f,

        // Front
          0.5f, -0.5f,   0.5f,   0.3f, 0.4f, 0.3f, 1.0f,    0.0f, 0.5f, 1.0f,
          0.0f,  0.5f,   0.0f,   0.3f, 0.4f, 0.3f, 1.0f,    0.0f, 0.5f, 1.0f,
         -0.5f, -0.5f,   0.5f,   0.3f, 0.4f, 0.3f, 1.0f,    0.0f, 0.5f, 1.0f,

        // Bottom
          0.0f, -0.5f,  -0.5f,   0.0f, 0.2f, 0.0f, 1.0f,    0.0f, -1.0f, 0.0f,
         -0.5f, -0.5f,   0.5f,   0.0f, 0.2f, 0.0f, 1.0f,    0.0f, -1.0f, 0.0f,
          0.5f, -0.5f,   0.5f,   0.0f, 0.2f, 0.0f, 1.0f,    0.0f, -1.0f, 0.0f,
    };

    GLuint vao;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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
