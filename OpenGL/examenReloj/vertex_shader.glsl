#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 colorito;

out vec4 Color;

void main()
{
	Color = colorito;
    gl_Position = vec4( position, 1.0);
}
