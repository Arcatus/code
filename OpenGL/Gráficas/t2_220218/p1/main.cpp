#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "math3d.h"
#include "shader_util.h"

const GLuint WIDTH = 512, HEIGHT = 512;
const float phi = 1.618f;

void error_callback(GLint error, const GLchar* description);
GLuint createModel(GLuint* vbo, GLuint* ebo);

int main(void) {

	glfwSetErrorCallback(error_callback);

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Tarea parte 1", NULL,NULL);

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	GLenum status = glewInit();

	if (status != GLEW_OK){
		std::cerr << "ERROR: " << glewGetErrorString(status) << std::endl;
		return 1;
	}
	
	GLuint shaderProgram = linkShaderProgram ("vertex_shader.glsl","fragment_shader.glsl");

	GLuint vao, vbo, ebo, location;
	vao = createModel(&vbo,&ebo);
	
	glViewport(0,0,WIDTH,HEIGHT);

	glClearColor(0.0f,0.0f,0.0f,1.0f);

	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

	glEnable(GL_DEPTH_TEST);

	location = glGetUniformLocation(shaderProgram,"rotation");

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shaderProgram);

		GLfloat time = (GLfloat)glfwGetTime();

		Matrix3x3 rotation;

		Matrix3x3MakeRotationY(time,&rotation);

		glUniformMatrix3fv(location,1,GL_TRUE,(GLfloat*)rotation.m);

		glBindVertexArray(vao);

		glDrawElements(GL_TRIANGLES,108,GL_UNSIGNED_INT,(GLvoid*)0);

		glBindVertexArray(0);

		glfwSwapBuffers(window);

	}

	glDeleteBuffers(1,&vbo);
	glDeleteBuffers(1,&ebo);
	glDeleteVertexArrays(1,&vao);
	glfwTerminate();

	return 0;
}

GLuint createModel(GLuint* vbo, GLuint* ebo){

	GLfloat vertices[] = 
	{
		//cubo
		  1.0f, 1.0f, -1.0f,		0.5f,0.1f,0.3f,1.0f,//0 110
		  1.0f, 1.0f,  1.0f,   		0.1f,0.4f,0.7f,1.0f,//1 111  
		 -1.0f, 1.0f,  1.0f,  		0.1f,0.8f,0.2f,1.0f,//2 011
		 -1.0f, 1.0f, -1.0f,   		0.9f,0.2f,0.3f,1.0f,//3 010
		  1.0f,-1.0f, -1.0f,  		0.2f,0.8f,0.6f,1.0f,//4 100
		  1.0f,-1.0f,  1.0f, 		0.1f,0.1f,0.1f,1.0f,//5 101
		 -1.0f,-1.0f,  1.0f,		0.7f,0.4f,0.9f,1.0f,//6 001
		 -1.0f,-1.0f, -1.0f,  		0.2f,0.6f,0.6f,1.0f,//7 000
		//azul
		 -(1.0f/phi), -phi, 0.0f,    	0.0f,0.0f,1.0f,1.0f,//8
		  (1.0f/phi), -phi, 0.0f,    	0.0f,0.0f,1.0f,1.0f,//9
		 -(1.0f/phi),  phi, 0.0f,  		0.0f,0.0f,1.0f,1.0f,//10
		  (1.0f/phi),  phi, 0.0f,    	0.0f,0.0f,1.0f,1.0f,//11
		//verde
		   0.0f, -(1.0f/phi), -phi,     0.0f,1.0f,0.0f,1.0f,//12
		   0.0f, -(1.0f/phi),  phi,     0.0f,1.0f,0.0f,1.0f,//13
		   0.0f,  (1.0f/phi), -phi,  	0.0f,1.0f,0.0f,1.0f,//14
		   0.0f,  (1.0f/phi),  phi,     0.0f,1.0f,0.0f,1.0f,//15
		//rojo
		   -phi, 0.0f, -(1.0f/phi),     1.0f,0.0f,0.0f,1.0f,//16
		    phi, 0.0f, -(1.0f/phi),     1.0f,0.0f,0.0f,1.0f,//17
		   -phi, 0.0f,  (1.0f/phi),   	1.0f,0.0f,0.0f,1.0f,//18
		    phi, 0.0f,  (1.0f/phi),     1.0f,0.0f,0.0f,1.0f,//19
	};

	GLuint elements[]=
	{
		//
		3,11,10,3,0,11,3,14,0,
		//n-r-r-n-a	
		0,17,11,17,19,11,19,1,11, 
		//a-n-v-n-a
		1,15,2,1,2,10,1,10,11,
		//
		10,2,18,10,18,16,10,16,3,
		//
		2,6,18,2,13,6,2,15,13, 
		//
		13,15,1,13,1,5,5,1,19, 
		//
		7,3,16,7,12,3,12,14,3,
		//a-n-r-r-n
		8,7,16,8,16,18,8,18,6,
		//v-n-r-n-v
		12,0,14,12,4,0,4,17,0,
		//a-a-n-v-n
		8,12,7,8,9,12,9,4,12,
		//a-n-r-r-n
		9,5,19,9,19,17,9,17,4,
		//a-a-n-v-n
		13,8,6,13,9,8,13,5,9
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
