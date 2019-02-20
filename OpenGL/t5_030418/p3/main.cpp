
#include <iostream> 
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_util.h"
#include "camera.h"
#include "math3d.h"

void error_callback(GLint error, const GLchar* description);
void poll_keyboard(GLFWwindow* window, Camera* camera);
void poll_mouse(GLFWwindow* window, Camera* camera);

const GLuint WIDTH = 512, HEIGHT = 512;

GLuint createModel(GLuint* vbo, GLuint* ebo);
GLuint createTextureObject();

GLfloat lastX = 256, lastY = 256, yaw = -287.0f, pitch = 0.0f;

int main()
{	
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);	
	
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL App", NULL, NULL);
	
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
	
	glewExperimental = GL_TRUE;

	GLenum status = glewInit();

	 if(status != GLEW_OK)
    {
        std::cerr << "Error: " << glewGetErrorString(status) << std::endl;

        return 1;
    }

    Camera camera;
    camera.position  = { 0.0f, 2.0f, 3.0f };
    camera.target    = { 0.0f, 0.0f,-1.0f };
    camera.up        = { 0.0f, 0.1f, 0.0f };
    camera.speed     = 0.1;
    camera.mouseInit = GL_TRUE;   

	GLuint shaderProgram = linkShaderProgram("vertex_shader.glsl","fragment_shader.glsl");
	
	GLuint vao, vbo, ebo, texture0;

	Matrix4x4 projection, view, model;

	Matrix4x4MakeIdentity(&model);
	Matrix4x4MakeScaling(10.0f,1.0f,100.0f,&model);

	vao = createModel(&vbo,&ebo);

	texture0 = createTextureObject();
	
	glViewport(0, 0, WIDTH, HEIGHT);
	
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	
	
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
        poll_keyboard(window,&camera);
        poll_mouse(window,&camera);

        Vector3 newTarget = camera.position + camera.target;
        Matrix4x4MakeView(&camera.position, &newTarget, &camera.up, &view);

        Matrix4x4MakePerspective(45.0f, WIDTH / HEIGHT, 0.1f, 100.f, &projection);

        Matrix4x4 mvp = projection * view * model;
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shaderProgram);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture0);

		glUniform1i(glGetUniformLocation(shaderProgram,"sampler0"),0);

		glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "model"),1, GL_TRUE, (GLfloat*)model.m);

        glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "mvp"),1, GL_TRUE, (GLfloat*)mvp.m);

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
	GLfloat vertices[] = 
	{    
		-1.0f, 0.0f, -1.0f, 	0.0f, 1.0f, 0.0f,		0.0f, 0.0f, 
		 1.0f, 0.0f, -1.0f,  	0.0f, 1.0f, 0.0f,		1.0f, 0.0f, 
		-1.0f, 0.0f,  1.0f,  	0.0f, 1.0f, 0.0f,		0.0f, 1.0f, 
		 1.0f, 0.0f,  1.0f,  	0.0f, 1.0f, 0.0f,	    1.0f, 1.0f
		  
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6*sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	return vao;
}

GLuint createTextureObject()
{
	GLuint* textureData0 = new GLuint[64*64];
	GLuint* textureData1 = new GLuint[32*32];
	GLuint* textureData2 = new GLuint[16*16];

	for(GLuint row = 0; row < 64; row++)
	{
		for(GLuint col = 0; col < 64; col++)
		{
			textureData0[64*row+col] = 0xFFFFFFFF;
		}
	}

	for(GLuint row = 0; row < 32; row++)
	{
		for(GLuint col = 0; col < 32; col++)
		{
			textureData1[32*row+col] = 0xFF0000FF; 
		}
	}

	for(GLuint row = 0; row < 16; row++)
	{
		for(GLuint col = 0; col < 16; col++)
		{
			textureData2[16*row+col] = 0xFF00FF00;
		}
	}

	GLuint texture;

	glGenTextures(1,&texture);

	glBindTexture(GL_TEXTURE_2D,texture);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,textureData0);
	glTexImage2D(GL_TEXTURE_2D,1,GL_RGBA,32,32,0,GL_RGBA,GL_UNSIGNED_BYTE,textureData1);
	glTexImage2D(GL_TEXTURE_2D,2,GL_RGBA,16,16,0,GL_RGBA,GL_UNSIGNED_BYTE,textureData2);

	glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL,2);

	glBindTexture(GL_TEXTURE_2D,0);

	return texture;
}

void poll_mouse(GLFWwindow* window, Camera* camera)
{
    GLdouble xpos, ypos;
    glfwGetCursorPos(window,&xpos,&ypos);

    if (camera->mouseInit)
    {
        lastX = xpos;
        lastY = ypos;
        camera->mouseInit = GL_FALSE;
    }    

    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = ypos - lastY;
    lastX = xpos;
    lastY = ypos;

    GLfloat sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   += xoffset;
    pitch += yoffset;

    if (pitch > 45.0f)
        pitch = 45.0f;
    if (pitch < -45.0f)
        pitch = -45.0f;

    Vector3 newTarget;
    newTarget.x = cos(yaw/180) * cos(pitch/180);
    newTarget.y = sin(pitch/180);
    newTarget.z = sin(yaw/180) * cos(pitch/180);

    camera->target = Vector3Normalize(newTarget);
}

void poll_keyboard(GLFWwindow* window, Camera* camera)
{
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        camera->position.y+=0.1;
    }

    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        camera->position.y-=0.1;
    }

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        Vector3 sideVector;
        Vector3CrossProduct(&camera->target, &camera->up, &sideVector);
        Vector3Normalize(&sideVector);

        camera->position = camera->position - camera->speed * sideVector;
    }

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        Vector3 sideVector;
        Vector3CrossProduct(&camera->target, &camera->up, &sideVector);
        Vector3Normalize(&sideVector);

        camera->position = camera->position + camera->speed * sideVector;
    }

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera->position = camera->position + camera->speed * camera->target;
    }

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera->position = camera->position - camera->speed * camera->target;
    }
}

void error_callback(GLint error, const GLchar* description)
{
    std::cerr << "Error " << error << ": " << description << std::endl;

    exit(1);
}
