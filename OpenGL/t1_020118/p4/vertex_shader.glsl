#version 330 core

layout (location = 0) in vec3 position;

uniform vec3 displacement;

void main()
{
	gl_Position = vec4(0.05 * position + displacement, 1.0);
}