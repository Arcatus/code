#version 330 core

in vec2 TexCoord;

out vec4 color;

uniform sampler2D sampler0;
uniform vec2 displacement;

void main()
{
	vec4 fragments = texture(sampler0,TexCoord + displacement);

	if (fragments.z < 0.001f)
	{
		discard;
	}

	color = fragments;		
}