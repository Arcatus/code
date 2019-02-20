#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"

const GLuint WIDTH = 512, HEIGHT = 512;

void error_callback(GLint error, const GLchar* description);
GLuint createModel(GLuint* vbo, GLuint* ebo);

int main(){

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

	if (status != GLEW_OK){
		std::cerr << "ERROR: " << glewGetErrorString(status) << std::endl;

		return 1;
	}
	
	GLuint shaderProgram = linkShaderProgram ( "vertex_shader.glsl", "fragment_shader.glsl");

	GLuint vao,vbo,ebo;
	vao = createModel(&vbo,&ebo);
	
	glViewport(0,0,WIDTH,HEIGHT);

	glClearColor(0.0f,0.0f,0.0f,1.0f);

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);

		glBindVertexArray(vao);

		glDrawElements(GL_TRIANGLES,60,GL_UNSIGNED_INT,(GLvoid*)0);

		glBindVertexArray(0);

		glfwSwapBuffers(window);

	}

	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1,&vao);
	glDeleteBuffers(1,&ebo);
	glfwTerminate();

	return 0;
}

GLuint createModel(GLuint* vbo, GLuint* ebo){

	GLfloat vertices[] = 
	{
		//top vertices
		  1.0f, 1.618f, 0.0f,	0.3f,0.4f,0.8f,1.0f,
		 -1.0f, 1.618f, 0.0f,   1.0f,0.0f,0.0f,1.0f,
		  0.0f,  1.0f, 1.618f,  1.0f,0.0f,0.0f,1.0f,
		  1.618f, 0.0f, 1.0f,   0.0f,1.0f,0.0f,1.0f,
		  1.618f, 0.0f, -1.0f,   0.0f,1.0f,0.0f,1.0f,
		  0.0f,  1.0f, -1.618f,  1.0f,0.0f,0.0f,1.0f,

		//bot vertices
		 -1.0f, -1.618f, 0.0f,   1.0f,0.0f,0.0f,1.0f,
		  -1.618f, 0.0f, -1.0f,   0.0f,1.0f,0.0f,1.0f,
		  0.0f,  -1.0f, 1.618f,  1.0f,0.0f,0.0f,1.0f,
		  1.0f, -1.618f, 0.0f,   1.0f,0.0f,0.0f,1.0f,
		  0.0f,  -1.0f, -1.618f,  1.0f,0.0f,0.0f,1.0f,
		  -1.618f, 0.0f, -1.0f,   0.0f,1.0f,0.0f,1.0f,
	};

	GLuint elements[]=
	{
		//top
		0,1,2,
		0,2,3,
		0,3,4,
		0,4,5,
		0,5,1,
		//mid
		1,7,2,2,7,8,
		2,8,3,3,8,9,
		3,9,4,4,9,10,
		4,10,5,5,10,11,
		5,11,1,1,11,7,
		//bot
		6,8,7,
		6,9,8,
		6,10,9,
		6,11,10,
		6,7,11
	};

	GLuint vao;

	glGenVertexArrays(1,&vao);
	glGenBuffers(1,vbo);
	glGenBuffers(1,ebo);

	glBindVertexArray(vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements),elements,GL_STATIC_DRAW);

	glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1,4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)) );

	glEnableVertexAttribArray(1);
	
	glBindBuffer(GL_ARRAY_BUFFER,0);
	
	glBindVertexArray(0);

	return vao;
}

void error_callback(GLint error, const GLchar* description){

	std::cerr << "ERROR " <<error << ": " << description << std::endl;
	
	fflush(stdin);
	std::cin.get();
	exit(1);

}