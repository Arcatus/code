#version 330 core

in vec4 Color;
in vec3 Normal;
in vec3 FragmentPosition;

out vec4 color;

uniform vec3 lightPosition0;
uniform vec3 lightPosition1;
uniform vec3 lightPosition2;
uniform vec3 lightPosition3;

uniform vec3 viewerPosition;

void main()
{
	vec4 ambientLight = vec4(0.1, 0.2, 0.3, 1.0);

	vec4 pointLight = vec4(0.3, 0.3, 0.3, 1.0);

	vec3 normal = normalize(Normal);

    vec3 lightDirection0 = normalize(lightPosition0 - FragmentPosition);
    vec3 lightDirection1 = normalize(lightPosition1 - FragmentPosition);
    vec3 lightDirection2 = normalize(lightPosition2 - FragmentPosition);
    vec3 lightDirection3 = normalize(lightPosition3 - FragmentPosition);

    vec3 viewDirection = normalize(viewerPosition - FragmentPosition);

    float diffuseFactor0 = max(dot(lightDirection0, Normal), 0.0);
    float diffuseFactor1 = max(dot(lightDirection1, Normal), 0.0);
    float diffuseFactor2 = max(dot(lightDirection2, Normal), 0.0);
    float diffuseFactor3 = max(dot(lightDirection3, Normal), 0.0);
    
    float specularFactor0 = 
    pow(max(dot(normalize(lightDirection0 + viewDirection),normal), 0.0), 32);

    float specularFactor1 = 
    pow(max(dot(normalize(lightDirection1 + viewDirection),normal), 0.0), 32);

    float specularFactor2 = 
    pow(max(dot(normalize(lightDirection2 + viewDirection),normal), 0.0), 32);

    float specularFactor3 = 
    pow(max(dot(normalize(lightDirection3 + viewDirection),normal), 0.0), 32);

    color = Color * ambientLight + 
    diffuseFactor0 * Color * pointLight + Color * pointLight * specularFactor0 * 4.0f +
    diffuseFactor1 * Color * pointLight + Color * pointLight * specularFactor1 * 4.0f +
    diffuseFactor2 * Color * pointLight + Color * pointLight * specularFactor2 * 4.0f +
    diffuseFactor3 * Color * pointLight + Color * pointLight * specularFactor3 * 4.0f;

}
