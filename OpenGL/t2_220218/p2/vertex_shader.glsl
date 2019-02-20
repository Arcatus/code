#version 330 core

layout (location = 0) in vec3 position;

uniform mat3 rotation;

void main()
{
	gl_Position = vec4( rotation  * position, 1.0);
}
