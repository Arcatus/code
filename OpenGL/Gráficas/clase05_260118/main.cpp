#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);
GLuint createModel(GLuint* vbo, GLuint* ebo, GLuint numSide);

int main()
{

	glfwSetErrorCallback(error_callback);
	
	glfwInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Ventana", NULL, NULL);
	
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	GLenum status = glewInit();

	if (status != GLEW_OK) { 
		std::cerr << "ERROR: " << glewGetErrorString(status) << std::endl;
		return 1;
	}

	GLuint shaderProgram = linkShaderProgram ( "vertex_shader.glsl","fragment_shader.glsl");

	GLuint vao, vbo, ebo;
	GLuint numSide = 60;
	vao = createModel(&vbo,&ebo,numSide);

	glViewport(0,0,WIDTH,HEIGHT);
	
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
 
		glBindVertexArray(vao);
		glDrawArrays(GL_POINTS,0,120);
		glDrawElements(GL_TRIANGLES,3 * (numSide - 2) ,GL_UNSIGNED_INT,(GLvoid*)0);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &ebo);

	glfwTerminate();
	return 0;
}

GLuint createModel(GLuint* vbo, GLuint* ebo, GLuint numSide) {

	GLfloat* vertices = new GLfloat[3 * numSide];

	for(GLuint i = 0; i < numSide; i++)
	{
		vertices[3 * i]     = 0.6f * cosf(2 * M_PI * i/numSide);
		vertices[3 * i + 1] = 0.6f * sinf(2 * M_PI * i/numSide);
		vertices[3 * i + 2] = 0.0f;
	}

	GLuint* elements = new GLuint[3 * (numSide - 2)];

	for(GLuint i = 0; i < (numSide - 2); i++)
	{
		elements[3 * i]     = 0;
		elements[3 * i + 1] = i + 1;
		elements[3 * i + 2] = i + 2;
	}

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glGenBuffers(1,vbo);
	glGenBuffers(1,ebo);

	
	glBindVertexArray(vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	
	glBufferData(GL_ARRAY_BUFFER,3 * sizeof(GLfloat) * numSide,vertices,GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,3 * sizeof(GLuint)  * (numSide - 2),elements,GL_STATIC_DRAW);

	
	glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	
	glEnableVertexAttribArray(0);

	
	glBindBuffer(GL_ARRAY_BUFFER,0);
	
	glBindVertexArray(0);

	delete[] vertices;
	delete[] elements;
	return vao;
}

void error_callback(GLint error, const GLchar* description) 
{	
	std::cerr << "ERROR " <<error << ": " << description << std::endl;
	fflush(stdin);
	std::cin.get();
	exit(1);
}
