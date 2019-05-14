#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in float id;

out float ID;

void main()
{
	ID = id;
	gl_Position = vec4(0.7 * position, 1.0);
}