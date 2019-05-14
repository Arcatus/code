#include "shader_util.h"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

GLuint linkShaderProgram(const char *vsFilename, const char *fsFilename)
{
    GLuint shaderProgram = glCreateProgram();

    string shaderStr = loadShaderCode(vsFilename);
    GLuint vertexShader = compileShaderObject(shaderStr.c_str(), GL_VERTEX_SHADER);

    shaderStr = loadShaderCode(fsFilename);
    GLuint fragmentShader = compileShaderObject(shaderStr.c_str(), GL_FRAGMENT_SHADER);

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    GLint success;
    GLchar infoLog[512];

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);

        cout << "Link Error: " << infoLog << endl;

        std::fflush(stdin);
        std::cin.get();

        exit(1);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

string loadShaderCode(const char* filename)
{
    string shaderCode;
    ifstream file(filename, std::ios::in);

    if (!file.good())
    {
        cout << "Can't read file " << filename << endl;

        std::fflush(stdin);
        std::cin.get();

        exit(1);
    }

    file.seekg(0, std::ios::end);
    shaderCode.resize((unsigned int)file.tellg());

    file.seekg(0, std::ios::beg);
    file.read(&shaderCode[0], shaderCode.size());
    file.close();

    return shaderCode;
}

GLuint compileShaderObject(const GLchar* shaderCode, GLenum shaderType)
{
    GLuint shaderObject = glCreateShader(shaderType);

    if(shaderObject == 0)
    {
        cout << "Error creating shader type: " << shaderType << endl;

        std::fflush(stdin);
        std::cin.get();

        exit(1);
    }

    glShaderSource(shaderObject, 1, &shaderCode, NULL);
    glCompileShader(shaderObject);

    GLint success;
    GLchar infoLog[512];

    glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shaderObject, 512, NULL, infoLog);

        cout << "Error compiling shader type: " << shaderType << endl;
        cout << infoLog << endl;

        std::fflush(stdin);
        std::cin.get();

        exit(1);
    }

    return shaderObject;
}
