#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"

const GLuint W = 512, H = 512;

GLuint createModel(GLuint* vbo, GLuint* ebo, const int modelo);

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

	GLuint shaderProgram  = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");
	GLuint shaderProgram2 = linkShaderProgram("vertex_shader.glsl","fragment_shader2.glsl");
	GLuint shaderProgram3 = linkShaderProgram("vertex_shader.glsl","fragment_shader3.glsl");
	GLuint shaderProgram4 = linkShaderProgram("vertex_shader.glsl","fragment_shader4.glsl");
	GLuint shaderProgram5 = linkShaderProgram("vertex_shader.glsl","fragment_shader5.glsl");

	
	GLuint vao[5], vbo[5], ebo[5];

	GLuint location;

	for (int i = 0; i < 5; ++i)
	{
		vao[i] = createModel(&vbo[i],&ebo[i],i);
	}
	
	glViewport(0, 0, W, H);
	
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		
		glClear(GL_COLOR_BUFFER_BIT);
		//linea
		glUseProgram(shaderProgram);
		glBindVertexArray(vao[0]);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,(GLvoid*)0);
		glBindVertexArray(0);

		//cuadro
		glUseProgram(shaderProgram2);
		glBindVertexArray(vao[1]);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,(GLvoid*)0);
		glBindVertexArray(0);

		//L
		glUseProgram(shaderProgram3);
		glBindVertexArray(vao[2]);
		glDrawElements(GL_TRIANGLES,12,GL_UNSIGNED_INT,(GLvoid*)0);
		glBindVertexArray(0);

		//Z
		glUseProgram(shaderProgram4);
		glBindVertexArray(vao[3]);
		glDrawElements(GL_TRIANGLES,12,GL_UNSIGNED_INT,(GLvoid*)0);
		glBindVertexArray(0);

		//T
		glUseProgram(shaderProgram5);
		glBindVertexArray(vao[4]);
		glDrawElements(GL_TRIANGLES,12,GL_UNSIGNED_INT,(GLvoid*)0);
		glBindVertexArray(0);
		
		glfwSwapBuffers(window);
	}
	glDeleteBuffers(1,vbo);
	glDeleteBuffers(1,ebo);
	glDeleteVertexArrays(1,vao);
	glfwTerminate();
	return 0;
}


GLuint createModel(GLuint* vbo, GLuint* ebo, const int modelo)
{
	GLfloat vertices0[] =  {
		-0.8f, 0.4f, 0.0f,//0  
		 0.0f, 0.4f, 0.0f, 
		-0.8f, 0.6f, 0.0f, 
		 0.0f, 0.6f, 0.0f, //3
	};
	GLuint elements0[] = {
		0,  1,  2,
		1,  3,  2,
	};
	GLfloat vertices1[] =  {
	//square
		0.2f, 0.2f, 0.0f, //4 -> 0
		0.6f, 0.2f, 0.0f,  
		0.6f, 0.6f, 0.0f, 
		0.2f, 0.6f, 0.0f, //7 -> 3
	};
	GLuint elements1[] = {
		0,  1,  3,
		1,  2,  3,
	};
	GLfloat vertices2[] =  {
				//L
		-0.8f, -0.2f, 0.0f, //8
		-0.6f, -0.2f, 0.0f, 
		-0.8f,  0.2f, 0.0f, 
		-0.6f,  0.2f, 0.0f, //11
		-0.8f, -0.4f, 0.0f, 
		-0.4f, -0.4f, 0.0f, 
		-0.4f, -0.2f, 0.0f, //14 
	};
	GLuint elements2[] = {
		 0,  1, 2,
		 1,  3, 2,
		 4,  5, 0,
		 5,  6, 0,
	};
	GLfloat vertices3[] =  {
	//Z
		-0.2f,  0.2f, 0.0f, //15
		-0.2f, -0.2f, 0.0f, 
		 0.0f, -0.2f, 0.0f, 
		 0.0f,  0.2f, 0.0f, //18
		 0.0f,  0.0f, 0.0f, 
		 0.0f, -0.4f, 0.0f, 
		 0.2f, -0.4f, 0.0f, 
		 0.2f,  0.0f, 0.0f,  //22
	};
	GLuint elements3[] = {
		 1,  2, 0,
		 2,  3, 0,
		 5,  6, 4,
		 6,  7, 4,
	};
	GLfloat vertices4[] =  {
	//T
		 0.4f,  0.0f, 0.0f, //23
		 0.4f, -0.2f, 0.0f, 
		 0.6f, -0.4f, 0.0f, 
		 0.8f, -0.4f, 0.0f, //26
		 1.0f, -0.2f, 0.0f, 
		 1.0f,  0.0f, 0.0f, 
		 0.6f,  0.0f, 0.0f, 
		 0.8f,  0.0f, 0.0f, //30
	};
	GLuint elements4[] = {
		 1, 4, 0,
		 4, 5, 0,
		 2, 3, 6,
		 3, 7, 6
	};

	GLuint vao;
	
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glGenBuffers(1, ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);

	switch(modelo)
	{
		case 0:
		{		
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices0), vertices0, GL_STATIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements0), elements0,GL_STATIC_DRAW);
			break;
		}
		case 1:
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements1), elements1,GL_STATIC_DRAW);
			break;
		}
		case 2:
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements2), elements2,GL_STATIC_DRAW);
			break;
		}
		case 3:
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements3), elements3,GL_STATIC_DRAW);
			break;
		}
		case 4:
		{			
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices4), vertices4, GL_STATIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements4), elements4,GL_STATIC_DRAW);
			break;
		}
		default:
		break;
	}
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
	return vao;
}