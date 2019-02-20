/*
    @title = Texturas.
    @Description = 
    Tablero de ajedrez, textura procedual, repeat S-T.
    @autor = arcatus
*/

#include <iostream> 
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>

#include "shader_util.h"
#include "math3d.h"

const GLuint W = 512, H = 512;

GLuint createModel(GLuint* vbo, GLuint* ebo);
GLuint createTextureObject();

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
	
	GLuint vao, vbo, ebo, texture0;
	vao = createModel(&vbo,&ebo);

	texture0 = createTextureObject();
	
	glViewport(0, 0, W, H);
	
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		
		glClear(GL_COLOR_BUFFER_BIT);

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


GLuint createModel(GLuint* vbo, GLuint* ebo)
{
	//	vertices,textura,color
	GLfloat vertices[] = 
	{    
		-0.5f, -0.5f, 0.0f, 	0.0f, 0.0f, 
		 0.5f, -0.5f, 0.0f, 	4.0f, 0.0f, 
		-0.5f,  0.5f, 0.0f, 	0.0f, 4.0f, 
		 0.5f,  0.5f, 0.0f, 	4.0f, 4.0f
		  
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1 , 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	return vao;
}

GLuint createTextureObject()
{
	GLuint* textureData = new GLuint[32*32];

	for(GLuint row = 0; row < 32; row++)
	{
		for(GLuint col = 0; col < 32; col++)
		if ( row < 16 && col < 16 || row > 16 && col > 16 )
		{
			textureData[32*row+col] = 0xFFFFFFFF;
		} else {
			textureData[32*row+col] = 0;
		}
	}

	GLuint texture;

	glGenTextures(1,&texture);
	glBindTexture(GL_TEXTURE_2D,texture);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,32,32,0,GL_RGBA,GL_UNSIGNED_BYTE,textureData);

	glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);

	glBindTexture(GL_TEXTURE_2D,0);
	return texture;
}
