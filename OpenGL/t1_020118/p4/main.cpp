#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"

const GLuint W = 512, H = 512;

GLuint modeloQueso(GLuint* vbo, GLuint* ebo);
GLuint modeloRaton(GLuint* vbo, GLuint* ebo);

void error_callback(GLint error, const GLchar* description);

int main()
{
	glfwSetErrorCallback(error_callback);
	glfwInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	
	GLFWwindow* window = glfwCreateWindow(W, H, "tarea 4", NULL, NULL);
	
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;

	glewInit();

	GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");
	
	GLuint vaoQ, vboQ, eboQ;
	GLuint vaoR, vboR, eboR;
	
	vaoQ = modeloQueso(&vboQ,&eboQ);
	vaoR = modeloRaton(&vboR,&eboR);
	
	glViewport(0, 0, W, H);
	
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	GLfloat currentTime = 0.0f;
    GLfloat elapsedTime = 0.0f;
    GLfloat oldTime     = 0.0f;
	
    GLfloat pos[] = 
    {
    	-0.7f,-0.8f, 0.0f, //R
    	-0.5f,-0.5f, 0.0f, //q1
    	-0.2f,-0.4f, 0.0f, //q2
		 0.0f,-0.1f, 0.0f, //q3
		 0.2f, 0.2f, 0.0f, //q4
		 0.0f, 0.5f, 0.0f, //q5
    };

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		currentTime = (GLfloat)glfwGetTime();
        elapsedTime += currentTime - oldTime;
        oldTime     = currentTime;

        if(elapsedTime > 6.0f)
        {
            elapsedTime = 0.0f;
        }
		
		glClear(GL_COLOR_BUFFER_BIT);
			
		glUseProgram(shaderProgram);

		glUniform4f(glGetUniformLocation(shaderProgram,"Color"), 1.0f, 1.0f, 0.0f, 1.0f);

		glUniform3f(glGetUniformLocation(shaderProgram,"displacement"),-0.5f,-0.5f, 0.0f);
		glBindVertexArray(vaoQ);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,(GLvoid*)0);

		glUniform3f(glGetUniformLocation(shaderProgram,"displacement"),-0.2f,-0.4f, 0.0f);
		glBindVertexArray(vaoQ);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,(GLvoid*)0);

		glUniform3f(glGetUniformLocation(shaderProgram,"displacement"), 0.0f,-0.1f, 0.0f);
		glBindVertexArray(vaoQ);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,(GLvoid*)0);

		glUniform3f(glGetUniformLocation(shaderProgram,"displacement"), 0.2f, 0.2f, 0.0f);
		glBindVertexArray(vaoQ);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,(GLvoid*)0);

		glUniform3f(glGetUniformLocation(shaderProgram,"displacement"), 0.0f, 0.5f, 0.0f);
		glBindVertexArray(vaoQ);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,(GLvoid*)0);

		glBindVertexArray(0);

		glUniform4f(glGetUniformLocation(shaderProgram,"Color"), 0.5f, 0.25f, 0.25f, 1.0f);
		glUniform3f(glGetUniformLocation(shaderProgram,"displacement"),
		pos[int(elapsedTime)*3],pos[int(elapsedTime)*3+1],pos[int(elapsedTime)*3+2]);
		
		glBindVertexArray(vaoR);
		glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,(GLvoid*)0);
		glBindVertexArray(0);
		
		glfwSwapBuffers(window);
	}
	glDeleteBuffers(1,&vboQ);
	glDeleteBuffers(1,&eboQ);
	glDeleteBuffers(1,&vboR);
	glDeleteBuffers(1,&eboR);
	glDeleteVertexArrays(1,&vaoQ);
	glDeleteVertexArrays(1,&vaoR);
	glfwTerminate();
	return 0;
}


GLuint modeloQueso(GLuint* vbo, GLuint* ebo)
{
	GLfloat vertices[] = 
	{
		-1.0f,-1.0f,0.0f,
		 1.0f,-1.0f,0.0f,
		 1.0f, 1.0f,0.0f,
		-1.0f, 1.0f,0.0f
	};
	
	GLuint elements[] = 
	{
		0,1,3,
		1,2,3
	};

	GLuint vao;
	
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glGenBuffers(1, ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements), elements,GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
	return vao;
}

GLuint modeloRaton(GLuint* vbo, GLuint* ebo)
{
	GLfloat vertices[] = 
	{
		-1.0f,-1.0f,0.0f,
		 1.0f,-1.0f,0.0f,
		 0.0f, 1.0f,0.0f
	};
	
	GLuint elements[] = 
	{
		0,1,2
	};

	GLuint vao;
	
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glGenBuffers(1, ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements), elements,GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
	return vao;
}

void error_callback(GLint error, const GLchar* description) {

	std::cerr << "ERROR " <<error << ": " << description << std::endl;
	fflush(stdin);
	std::cin.get();
	exit(1);
}
