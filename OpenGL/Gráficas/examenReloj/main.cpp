#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);

GLuint crearManecilla(GLuint* ebo, GLuint* vbo, GLuint vertex);
GLuint crearIndicadores(GLuint* ebo, GLuint* vbo);

int main()
{
    glfwSetErrorCallback(error_callback);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGLApp",NULL,NULL);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "GLEW Error: " << glewGetErrorString(status) << std::endl;

        std::fflush(stdin);
        std::cin.get();

        return 1;
    }

    GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");
    GLuint shaderIndicator = linkShaderProgram("vertex_shader.glsl","fragment_indicator.glsl");

    GLuint vao_m, vao_i, vbo_m, ebo_i, ebo_m, vbo_i;

    vao_i = crearIndicadores(&vbo_i,&ebo_i);


    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    GLfloat deltaTiempo;

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
            
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        deltaTiempo = glfwGetTime();

        if(deltaTiempo > 61.0f || deltaTiempo < 1.0f)
        {
            glfwSetTime(1.0f);
        }

        vao_m = crearManecilla(&vbo_m,&ebo_m,int(deltaTiempo));

        glBindVertexArray(vao_m);
        glDrawArrays(GL_POINTS, 0, 61);
        glDrawElements(GL_LINES,2,GL_UNSIGNED_INT,(GLvoid*)0);
        glBindVertexArray(0);

        glUseProgram(shaderIndicator);
        glBindVertexArray(vao_i);
        glDrawElements(GL_TRIANGLES,24,GL_UNSIGNED_INT,(GLvoid*)0);
        glBindVertexArray(0);        

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao_m);
    glDeleteVertexArrays(1, &vao_i);
    glDeleteBuffers(1, &vbo_m);
    glDeleteBuffers(1, &vbo_i);

    glfwTerminate();
}

GLuint crearManecilla(GLuint* ebo, GLuint* vbo, GLuint vertex)
{

    GLfloat* vertices = new GLfloat[ (3 * 60) + 3 ];
    
    for(GLuint i = 1; i <= 60; ++i)
    {
        vertices[3 * i]     = 0.7f * sinf(2 * M_PI * (i-1)/60);
        vertices[3 * i + 1] = 0.7f * cosf(2 * M_PI * (i-1)/60);
        vertices[3 * i + 2] = 0.0f;
    }
    
    vertices[0] = 0.0f;
    vertices[1] = 0.0f;
    vertices[2] = 0.0f;

    GLuint elements[] = {
        0,vertex
    };

    GLuint vao;
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, 183 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements),elements,GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    delete[] vertices;

    return vao;
}

GLuint crearIndicadores(GLuint* ebo, GLuint* vbo)
{
    GLfloat vertices[] = 
    {
        /*12 - verde*/
        -0.05f,0.65f,0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
         0.05f,0.65f,0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
         0.05f,0.75f,0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        -0.05f,0.75f,0.0f, 0.0f, 1.0f, 0.0f, 1.0f, //3
        /*3 - azul*/
         0.65f,-0.05f,0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
         0.75f,-0.05f,0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
         0.75f, 0.05f,0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
         0.65f, 0.05f,0.0f, 0.0f, 0.0f, 1.0f, 1.0f, //7
        /*6 - verde*/
        -0.05f,-0.75f,0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
         0.05f,-0.75f,0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 
         0.05f,-0.65f,0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        -0.05f,-0.65f,0.0f, 0.0f, 1.0f, 0.0f, 1.0f, //11
        /*9 - azul*/
        -0.75f,-0.05f,0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.65f,-0.05f,0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.65f, 0.05f,0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.75f, 0.05f,0.0f, 0.0f, 0.0f, 1.0f, 1.0f, //15
    };
    GLuint elements[] = {
        0,  1, 3,
        1,  2, 3,
        4,  5, 7,
        5,  6, 7,
        8,  9,11,
        9, 10,11,
        12,13,15,
        13,14,15
    };

    GLuint vao;
    
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements),elements,GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return vao;
}

void error_callback(GLint error, const GLchar* description)
{
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;

    std::fflush(stdin);
    std::cin.get();

    exit(1);
}
