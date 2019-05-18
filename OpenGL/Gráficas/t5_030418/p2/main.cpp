
#include <iostream> 
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "joystick.h"
#include "math3d.h"
#include "texture.h"

void error_callback(GLint error, const GLchar* description);
void poll_keyboard(GLFWwindow* window, Joystick* joystick);

const GLuint WIDTH = 512, HEIGHT = 512;

GLuint createModel(GLuint* vbo, GLuint* ebo);

enum Buttons { UP, DOWN, LEFT, RIGHT};

int main()
{	
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);	
	
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL App", NULL, NULL);
	
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
	
	glewExperimental = GL_TRUE;

	GLenum status = glewInit();

	 if(status != GLEW_OK)
    {
        std::cerr << "Error: " << glewGetErrorString(status) << std::endl;

        return 1;
    }

    Joystick joystick;
    joystick.buttonEvent = DOWN;
    
	GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");
	
	GLuint vao, vbo, ebo, texture0;

	vao = createModel(&vbo,&ebo);

	texture0 = createTextureObject("death_scythe.png");
	
	glViewport(0, 0, WIDTH, HEIGHT);
	
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	glEnable(GL_DEPTH_TEST);
  
    GLfloat currentTime = 0.0f;
    GLfloat oldTime     = 0.0f;
    GLfloat elapsedTime = 0.0f;

	Vector3 d = { };
	GLuint frameDisplacement = 0;
	GLfloat adjustY = 0.0f, adjustX = 0.0f;
	
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

        poll_keyboard(window,&joystick);

        currentTime = (GLfloat) glfwGetTime();
        elapsedTime += currentTime - oldTime;
        oldTime = currentTime;

        if (frameDisplacement > 3) {
        	switch(joystick.buttonEvent)
        	{
        		case    UP: adjustY = -0.75f; break;
	        	case  DOWN:	adjustY =  0.0f ; break;
	        	case  LEFT: adjustY = -0.25f; break;
	        	case RIGHT: adjustY = -0.50f; break;
	        	default: break;		
        	}
        	frameDisplacement = 0;
        }

        if (elapsedTime > 0.08f) {
			d.x = d.x + 0.25f;
			glUniform2f(glGetUniformLocation(shaderProgram, "displacement"), d.x, adjustY);
			elapsedTime = 0;
			frameDisplacement++;
		}
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shaderProgram);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture0);

		glUniform1i(glGetUniformLocation(shaderProgram,"sampler0"),0);

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,(GLvoid*)0);
		glBindVertexArray(0);
		
		glfwSwapBuffers(window);
	}
	glDeleteBuffers(1,&vbo);
	glDeleteVertexArrays(1,&vao);
	glfwTerminate();
	return 0;
}

void poll_keyboard(GLFWwindow* window, Joystick* joystick)
{

    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        joystick->buttonEvent = LEFT;
    }

    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
     	joystick->buttonEvent = RIGHT;	
    }

    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) 
    {
     	joystick->buttonEvent = UP;		
    }

    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
     	joystick->buttonEvent = DOWN;
    }

	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}


GLuint createModel(GLuint* vbo, GLuint* ebo)
{
	GLfloat vertices[] = 
	{    
		-0.5f, -0.5f, 0.0f,   0.0f,  0.75f,   
		 0.5f, -0.5f, 0.0f,  0.25f,  0.75f,   
		-0.5f,  0.5f, 0.0f,   0.0f,  1.0f,  
		 0.5f,  0.5f, 0.0f,  0.25f,  1.0f   
		  
	};

	GLuint elements[] = 
	{
		0,1,2,
		1,3,2
	};

	GLuint vao;
	
	glGenVertexArrays(1,&vao);
	
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);
	glGenBuffers(1, ebo);
	
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 	* sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
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
