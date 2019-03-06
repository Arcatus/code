#include <iostream> 
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	
	GLFWwindow* window = glfwCreateWindow(512,512, "OpenGL App", NULL, NULL);
	
	glfwMakeContextCurrent(window);

	glewInit();

	glewExperimental = GL_TRUE;

	GLfloat vertices[] = 
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	GLuint vbo;

	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glViewport(0, 0, 512, 512);

	glClearColor(0.0f,5.0f,5.0f,1.0f);
	
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}