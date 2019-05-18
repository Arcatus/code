#include <iostream> 
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>

#include "shader_util.h"
//#include "math3d.h"

const GLuint W = 728, H = 512;

int main()
{
	glfwInit();

	// Set up the OpenGL version we'll be using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);

	// Create window-context
	GLFWwindow* window = glfwCreateWindow(W, H, "esfera", nullptr, nullptr);

	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;

	glewInit();

	GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

	// vertex fetch the data that goes to vertex stage
	GLuint vao;
	glCreateVertexArrays(1,&vao);
	glBindVertexArray(vao);

	// set the created program as the current active
	glUseProgram(shaderProgram);

	glViewport(0, 0, W, H);

	glClearColor(0.0f,0.5f,1.0f,1.0f);

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	

	return 0;
}