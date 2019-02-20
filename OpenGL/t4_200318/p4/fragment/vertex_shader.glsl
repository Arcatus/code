#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec3 normal;

out vec4 Color;
out vec3 Normal;
out vec3 FragmentPosition;

uniform mat4 model;
uniform mat4 mvp;

void main()
{
	Color = color;
    Normal = normal;   
    FragmentPosition = vec3(model * vec4(position, 1.0));
	
    gl_Position = mvp * vec4(position, 1.0);
}
