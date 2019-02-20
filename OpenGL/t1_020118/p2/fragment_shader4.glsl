#version 330 core
in float ID;
out vec4 pixel;

uniform float color;

void main()
{
	pixel = vec4(color+0.5f,color-0.4f,color-0.2f,1.0f);
}