#include <iostream> 
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader_util.h"

const GLuint W = 512, H = 512;

GLuint createModel(GLuint* vbo);

int main()
{	
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);	
	
	GLFWwindow* window = glfwCreateWindow(W, H, "Triangulo", NULL, NULL);
	
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;

	glewInit();

	GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");
	
	GLuint vao, vbo;
	vao = createModel(&vbo);
	
	glViewport(0, 0, W, H);
	
	glClearColor(0.0f,0.0f,0.2f,1.0f);
	
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES,0,3);
		glBindVertexArray(0);
		
		glfwSwapBuffers(window);
	}
	glDeleteBuffers(1,&vbo);
	glDeleteVertexArrays(1,&vao);
	glfwTerminate();
	return 0;
}


GLuint createModel(GLuint* vbo)
{
	GLfloat vertices[] = 
	{
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f
	};
	GLuint vao;
	
	glGenVertexArrays(1,&vao);
	
	glBindVertexArray(vao);
	
	glGenBuffers(1, vbo);
	
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1 , 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	return vao;
}