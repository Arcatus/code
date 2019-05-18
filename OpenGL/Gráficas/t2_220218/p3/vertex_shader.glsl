#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 trans1;
uniform mat4 trans2;

uniform bool sel;

void main()
{
	if(sel)
	{
		gl_Position = trans1 * vec4(position, 1.0);
	} else {
		gl_Position = trans2 * vec4( -1 * position, 1.0);
	}
	
}
