#version 330 core

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragmentPosition;

out vec4 color;

uniform sampler2D sampler0;

void main()
{
	color = texture(sampler0,TexCoord);
}