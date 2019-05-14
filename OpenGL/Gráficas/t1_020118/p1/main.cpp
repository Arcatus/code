#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"

const GLuint W = 512, H = 512;

GLuint createModel(GLuint* vbo, GLuint* ebo);

int main()
{
	glfwInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	
	GLFWwindow* window = glfwCreateWindow(W, H, "Tetrominos", NULL, NULL);
	
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;

	glewInit();

	GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");

	GLuint vao, vbo, ebo;

	GLuint location;

	vao = createModel(&vbo,&ebo);
	
	glViewport(0, 0, W, H);
	
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	location = glGetUniformLocation(shaderProgram,"color");	

	GLfloat color = 0.1f;
	
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);

		glUniform1f(location,color);

		glBindVertexArray(vao);

		glDrawElements(GL_TRIANGLES,48,GL_UNSIGNED_INT,(GLvoid*)0);

		glBindVertexArray(0);
		
		glfwSwapBuffers(window);
	}
	glDeleteBuffers(1,&vbo);
	glDeleteBuffers(1,&ebo);
	glDeleteVertexArrays(1,&vao);
	glfwTerminate();
	return 0;
}


GLuint createModel(GLuint* vbo, GLuint* ebo)
{
	GLfloat vertices[] = 
	{
		//line
		-0.8f, 0.4f, 0.0f, 0.0f, //0
		 0.0f, 0.4f, 0.0f, 0.0f,
		-0.8f, 0.6f, 0.0f, 0.0f,
		 0.0f, 0.6f, 0.0f, 0.0f,//3
		//square
		 0.2f, 0.2f, 0.0f, 1.0f,//4
		 0.6f, 0.2f, 0.0f, 1.0f, 
		 0.6f, 0.6f, 0.0f, 1.0f,
		 0.2f, 0.6f, 0.0f, 1.0f,//7
		//L
		-0.8f, -0.2f, 0.0f, 2.0f,//8
		-0.6f, -0.2f, 0.0f, 2.0f,
		-0.8f,  0.2f, 0.0f, 2.0f,
		-0.6f,  0.2f, 0.0f, 2.0f,//11
		-0.8f, -0.4f, 0.0f, 2.0f,
		-0.4f, -0.4f, 0.0f, 2.0f,
		-0.4f, -0.2f, 0.0f, 2.0f, //14
		//Z
		-0.2f,  0.2f, 0.0f, 3.0f,//15
		-0.2f, -0.2f, 0.0f, 3.0f,
		 0.0f, -0.2f, 0.0f, 3.0f,
		 0.0f,  0.2f, 0.0f, 3.0f,//18
		 0.0f,  0.0f, 0.0f, 3.0f,
		 0.0f, -0.4f, 0.0f, 3.0f,
		 0.2f, -0.4f, 0.0f, 3.0f,
		 0.2f,  0.0f, 0.0f, 3.0f, //22
		//T
		 0.4f,  0.0f, 0.0f, 4.0f,//23
		 0.4f, -0.2f, 0.0f, 4.0f,
		 0.6f, -0.4f, 0.0f, 4.0f,
		 0.8f, -0.4f, 0.0f, 4.0f,//26
		 1.0f, -0.2f, 0.0f, 4.0f,
		 1.0f,  0.0f, 0.0f, 4.0f,
		 0.6f,  0.0f, 0.0f, 4.0f,
		 0.8f,  0.0f, 0.0f, 4.0f,//30
	};
	GLuint elements[] = {
		0,  1,  2,
		1,  3,  2,
		4,  5,  7,
		5,  6,  7,
		 8,  9, 10,
		 9, 11, 10,
		12, 13,  8,
		13, 14,  8,
		16, 17, 15,
		17, 18, 15,
		20, 21, 19,
		21, 22, 19,
		24, 27, 23,
		27, 28, 23,
		25, 26, 29,
		26, 30, 29
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return vao;
}