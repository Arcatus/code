#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec3 Normal;
out vec3 FragmentPosition;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 mvp;

void main()
{
    Normal = normal;
    TexCoord = texCoord;
    FragmentPosition = vec3(model * vec4(position, 1.0));

    gl_Position = mvp * vec4(position, 1.0);
}