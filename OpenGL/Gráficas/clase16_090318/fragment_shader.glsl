#version 330 core

in vec4 Color;
in vec3 Normal;
in vec3 FragmentPosition;

out vec4 color;

uniform vec3 lightDirection;
uniform vec3 lightPosition;
uniform float innerCutOff;
uniform float outerCutOff;

void main()
{
	vec3 lightDir = normalize(lightPosition - FragmentPosition);
    
    vec4 ambientLight = vec4(0.1, 0.1, 0.1, 1.0);
    vec4 diffuseLight = vec4(0.8, 0.8, 0.8, 1.0);

    // diffuse
    float diffuseFactor = max(dot(lightDir, Normal), 0.0);
    vec4 diffuse = diffuseLight * diffuseFactor;

    // spotlight (soft-edges)

    float theta = dot(lightDir,normalize(-lightDirection));
    float epsilon = innerCutOff - outerCutOff;
    float intensity = clamp((theta - outerCutOff) / epsilon, 0.0, 1.0);

    // add intensity of spotlight to other lights

	color = Color * ambientLight + diffuse * intensity * Color;
}
