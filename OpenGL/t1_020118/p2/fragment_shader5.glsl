#version 330 core
in float ID;
out vec4 pixel;

uniform float color;

void main()
{
	pixel = vec4(color-0.3f,color+0.1f,color-0.5f,1.0f);
}