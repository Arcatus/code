#ifndef INPUT_H
#define INPUT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "camera.h"

void poll_keyboard(GLFWwindow* window, Camera* camera, GLfloat deltaTime);
void poll_mouse(GLFWwindow* window, Camera* camera);

#endif // INPUT_H
