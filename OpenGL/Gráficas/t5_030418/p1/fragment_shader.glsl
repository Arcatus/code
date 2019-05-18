#version 330 core

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragmentPosition;

out vec4 color;

uniform sampler2D sampler0;

uniform vec3 lightPosition;

void main()
{
	vec4 ambientLight = vec4(0.2, 0.2, 0.2, 1.0);
	vec4 pointLight   = vec4(0.8, 0.8, 0.8, 1.0);

	vec3 lightDirection = normalize(lightPosition - FragmentPosition);

	float diffuseFactor = max(dot(lightDirection, Normal), 0.0);

  	color = (ambientLight + pointLight * diffuseFactor) * texture(sampler0,TexCoord);
}