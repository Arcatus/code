#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <cstdlib>
#include <FreeImage.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint createTextureObject(const GLchar* filename);

#endif // TEXTURE_H