#version 330 core

in vec2 TexCoord;

out vec4 color;

uniform sampler2D sampler0;
uniform sampler2D sampler1;

void main()
{
  	color = mix(texture(sampler1, TexCoord),texture(sampler0, TexCoord),0.5);
}
