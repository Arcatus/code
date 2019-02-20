#version 330 core

layout (location = 0) in vec3 position;

uniform vec3 scaling;

void main()
{
	gl_Position = vec4(0.15 * position, 1.0);
}
