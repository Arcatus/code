#ifndef SHADER_UTIL_H
#define SHADER_UTIL_H

#include <iostream>
#include <vector>
#include <GL/glew.h>

std::string loadShaderCode(const GLchar* filename);
GLuint compileShaderObject(const GLchar *shaderCode, GLenum shaderType);
GLuint linkShaderProgram(const GLchar* vsFilename, const GLchar* fsFilename);

GLuint createShaderProgram(std::vector<std::string>& filenames,
                           std::vector<GLenum>& shaderTypes);

#endif // SHADER_UTIL_H
