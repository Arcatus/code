#ifndef SHADER_UTIL_H
#define SHADER_UTIL_H

#include <iostream>
#include <fstream>
#include <GL/glew.h>

GLuint linkShaderProgram(const char* vsFilename, const char* fsFilename);
std::string loadShaderCode(const char* filename);
GLuint compileShaderObject(const GLchar *shaderCode, GLenum shaderType);

#endif // SHADER_UTIL_H
