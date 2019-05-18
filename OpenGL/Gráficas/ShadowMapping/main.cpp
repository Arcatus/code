
#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "math3d.h"
#include "camera.h"
#include "input.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);

GLuint createPlane(GLuint* vbo, GLuint* ebo);
GLuint createModel(GLuint* vbo);

GLuint createDepthTexture(GLuint width, GLuint height);
GLuint createFrameBuffer(GLuint depthTexture);

void renderScene(GLuint shaderProgram, GLuint* vao, Matrix4x4& model);

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
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "Error: " << glewGetErrorString(status) << std::endl;

        return 1;
    }

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl",
                                             "fragment_shader.glsl");

    GLuint depthSP       = linkShaderProgram("depth_vs.glsl",
                                             "depth_fs.glsl");

    GLuint testSP        = linkShaderProgram("test_vs.glsl",
                                             "test_fs.glsl");

    GLuint depthTexture = createDepthTexture(1024, 1024);
    GLuint fbo          = createFrameBuffer(depthTexture);

    Camera camera;
    camera.position = { 0.0f, 1.0f,  3.0f };
    camera.target   = { 0.0f, 0.0f, -1.0f };
    camera.up       = { 0.0f, 1.0f,  0.0f };
    camera.mouseX   = 0.0f;
    camera.mouseY   = 0.0f;
    camera.mouseInit = GL_TRUE;

    Matrix4x4 model;

    Matrix4x4 projection;
    Matrix4x4MakePerspective(45.0f, WIDTH / HEIGHT, 0.1f, 100.0f, &projection);

    Matrix4x4 offset;
    Matrix4x4MakeScaling(0.5f, 0.5f, 0.5f, &offset);
    offset.m[0][3] = 0.5f;
    offset.m[1][3] = 0.5f;
    offset.m[2][3] = 0.5f;

    GLuint vao[2], vbo[2], ebo;
    vao[0] = createPlane(&vbo[0], &ebo);
    vao[1] = createModel(&vbo[1]);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    GLfloat currentTime = 0.0f;
    GLfloat deltaTime   = 0.0f;
    GLfloat oldTime     = 0.0f;

    while(!glfwWindowShouldClose(window))
    {
        currentTime = (GLfloat)glfwGetTime();
        deltaTime   = currentTime - oldTime;
        oldTime     = currentTime;

        glfwPollEvents();
        poll_keyboard(window, &camera, deltaTime);
        poll_mouse(window, &camera);

        // Prepare lightMatrices
        Vector3 lightPosition = { 0.0f, 1.5f, 0.0f };
        Vector3 lightTarget   = { 0.0f, 0.0f, 0.0f };
        Vector3 lightUp       = { 0.0f, 1.0f, 0.0f };

        lightPosition.x = 2.0f * sinf(currentTime);
        lightPosition.z = 2.0f * cosf(currentTime);

        Matrix4x4 lightView;
        Matrix4x4MakeView(&lightPosition, &lightTarget, &lightUp, &lightView);

        Matrix4x4 lightProjection;
        //Matrix4x4MakeOrthographic(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, 7.5f, &lightProjection);
        Matrix4x4MakePerspective(45.0f, WIDTH / HEIGHT, 1.0f, 7.5f, &lightProjection);

        Matrix4x4 lightMvp = lightProjection * lightView;

        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        glViewport(0, 0, 1025, 1024);
        glClear(GL_DEPTH_BUFFER_BIT);

        glUseProgram(depthSP);


        glUniformMatrix4fv(glGetUniformLocation(depthSP, "lightMvp"),
                           1, GL_TRUE, (GLfloat*)lightMvp.m);

        glCullFace(GL_FRONT);
        renderScene(depthSP, vao, model);
        glCullFace(GL_BACK);

        // Render to texture
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        glViewport(0, 0, WIDTH, HEIGHT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, depthTexture);

        Matrix4x4 view;
        Vector3 newTarget = camera.position + camera.target;
        Matrix4x4MakeView(&camera.position, &newTarget, &camera.up, &view);

        Matrix4x4 vp = projection * view;

        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "vp"),
                           1, GL_TRUE, (GLfloat*)vp.m);

        glUniform3f(glGetUniformLocation(shaderProgram, "lightPosition"),
                    lightPosition.x, lightPosition.y, lightPosition.z);

        lightMvp = offset * lightMvp;

        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "lightMvp"),
                           1, GL_TRUE, (GLfloat*)lightMvp.m);

        renderScene(shaderProgram, vao, model);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(2, vao);
    glDeleteBuffers(2, vbo);
    glDeleteBuffers(1, &ebo);

    glfwTerminate();
}

void error_callback(GLint error, const GLchar* description)
{
    std::cerr << "Error " << error << ": " << description << std::endl;

    exit(1);
}

GLuint createPlane(GLuint* vbo, GLuint* ebo)
{
    GLfloat vertices[] =
    {
        -1.0f, -1.0f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 1.0f, 0.0f,    0.0f, 0.0f,
        -1.0f,  1.0f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 1.0f, 0.0f,    0.0f, 1.0f,
         1.0f, -1.0f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 1.0f, 0.0f,    1.0f, 0.0f,
         1.0f,  1.0f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 1.0f, 0.0f,    1.0f, 1.0f,
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(GLfloat), (GLvoid*)(7 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(GLfloat), (GLvoid*)(10 * sizeof(GLfloat)));
    glEnableVertexAttribArray(3);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return vao;
}

GLuint createModel(GLuint* vbo)
{
    GLfloat vertices[] =
    {
        // Left
         -0.5f, -0.5f,   0.5f,   1.0f, 0.0f, 0.0f, 1.0f,   -1.0f, 0.25f, -0.5f,
          0.0f,  0.5f,   0.0f,   1.0f, 0.0f, 0.0f, 1.0f,   -1.0f, 0.25f, -0.5f,
          0.0f, -0.5f,  -0.5f,   1.0f, 0.0f, 0.0f, 1.0f,   -1.0f, 0.25f, -0.5f,

        // Right
          0.0f, -0.5f,  -0.5f,   1.0f, 0.0f, 0.0f, 1.0f,    1.0f, 0.25f, -0.5f,
          0.0f,  0.5f,   0.0f,   1.0f, 0.0f, 0.0f, 1.0f,    1.0f, 0.25f, -0.5f,
          0.5f, -0.5f,   0.5f,   1.0f, 0.0f, 0.0f, 1.0f,    1.0f, 0.25f, -0.5f,

        // Front
          0.5f, -0.5f,   0.5f,   1.0f, 0.0f, 0.0f, 1.0f,    0.0f, 0.5f, 1.0f,
          0.0f,  0.5f,   0.0f,   1.0f, 0.0f, 0.0f, 1.0f,    0.0f, 0.5f, 1.0f,
         -0.5f, -0.5f,   0.5f,   1.0f, 0.0f, 0.0f, 1.0f,    0.0f, 0.5f, 1.0f,

        // Bottom
          0.0f, -0.5f,  -0.5f,   1.0f, 0.0f, 0.0f, 1.0f,    0.0f, -1.0f, 0.0f,
         -0.5f, -0.5f,   0.5f,   1.0f, 0.0f, 0.0f, 1.0f,    0.0f, -1.0f, 0.0f,
          0.5f, -0.5f,   0.5f,   1.0f, 0.0f, 0.0f, 1.0f,    0.0f, -1.0f, 0.0f,
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

GLuint createDepthTexture(GLuint width, GLuint height)
{
    GLuint depthTexture;

    glGenTextures(1, &depthTexture);

    glBindTexture(GL_TEXTURE_2D, depthTexture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);

    GLfloat borderColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    return depthTexture;
}

GLuint createFrameBuffer(GLuint depthTexture)
{
    GLuint fbo;

    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthTexture, 0);

    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return fbo;
}

void renderScene(GLuint shaderProgram, GLuint* vao, Matrix4x4& model)
{
    Matrix4x4 scaling;
    Matrix4x4MakeScaling(10.0f, 10.0f, 10.0f, &scaling);

    Matrix4x4 rotation;
    Vector3 axis = { 1.0f, 0.0f, 0.0f };
    Matrix4x4MakeRotation(&axis, -90.0f, &rotation);

    model = rotation * scaling;

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"),
                       1, GL_TRUE, (GLfloat*)model.m);

    glBindVertexArray(vao[0]);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
    glBindVertexArray(0);

    Matrix4x4MakeTranslation(0.0f, 0.5f, 0.0f, &model);

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"),
                       1, GL_TRUE, (GLfloat*)model.m);

    glBindVertexArray(vao[1]);
    glDrawArrays(GL_TRIANGLES, 0, 12);
    glBindVertexArray(0);
}
