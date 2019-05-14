#version 330 core

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragmentPosition;

out vec4 color;

uniform vec3 lightPosition;

void main()
{
	vec4 colorTemporal = vec4(0.5,0.0,0.0,1.0);

	vec4 ambientLight = vec4(0.1,0.1,0.1,1.0f);
	vec4 pointLight = vec4(0.1,0.1,0.1,1.0f);

	vec3 lightDirection = normalize(lightPosition - FragmentPosition);

	float diffuseFactor = max(dot(lightDirection,Normal), 0.0);

    color = colorTemporal * ambientLight + colorTemporal * pointLight * diffuseFactor;
}
