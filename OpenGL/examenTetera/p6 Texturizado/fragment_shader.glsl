#version 330 core

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragmentPosition;

out vec4 color;

uniform vec3 lightPosition;
uniform sampler2D sampler0;

void main()
{
	vec4 ambientLight = vec4(0.05, 0.05, 0.05, 1.0f);
	vec4 pointLight   = vec4(0.15, 0.15, 0.15, 1.0f);

	vec3 lightDirection = normalize(lightPosition - FragmentPosition);

	float diffuseFactor = max(dot(lightDirection,Normal), 0.0);

    color = (ambientLight + pointLight * diffuseFactor ) * texture(sampler0,TexCoord);
}
