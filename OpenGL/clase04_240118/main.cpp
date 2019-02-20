#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader_util.h"

const GLuint W = 512, H = 512;

void error_callback(GLint error, const GLchar* description);

GLuint createModel(GLuint* vbo, GLuint* ebo);

int main()
{
	glfwSetErrorCallback(error_callback);
	
	glfwInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(W, H, "Triangulo", NULL, NULL);
	
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;

	GLenum status = glewInit();

	if(status != GLEW_OK) {
		std::cerr << "Error: " << glewGetErrorString(status) << std::endl;
		return 1;
	}

	GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");
	
	GLuint vao, vbo, ebo, location;
	vao = createModel(&vbo, &ebo);
	
	glViewport(0, 0, W, H);
	
	glClearColor(0.0f,0.0f,0.2f,1.0f);

	GLfloat scale;

	location = glGetUniformLocation(shaderProgram,"scale");
	
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);

		scale = sinf((GLfloat)glfwGetTime()) / 2 + 0.5f;

		glUniform1f(location,scale);

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,(GLvoid*)0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	
	glDeleteBuffers(1,&vbo);
	glDeleteVertexArrays(1,&vao);
	glDeleteBuffers(1,&ebo);
	glfwTerminate();
	return 0;
}

GLuint createModel(GLuint* vbo, GLuint* ebo)
{
	GLfloat vertices[] = 
	{
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
	};

	GLuint elements[] = 
	{
		0,1,2,
		1,3,2
	};

	GLuint vao;
	
	glGenVertexArrays(1,&vao);
	glGenBuffers(1, vbo);
	glGenBuffers(1, ebo);
	
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1 , 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	return vao;
}

void error_callback(GLint error, const GLchar* description)
{
	fflush(stdin);
	std::cerr << "Error " << ": " << description << std::endl;
	exit(1);
}