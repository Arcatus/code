#version 330 core
 
in vec4 Color;
out vec4 color;

uniform float scale;

void main()
{
	color = scale * Color;
}