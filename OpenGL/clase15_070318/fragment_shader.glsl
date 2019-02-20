#version 330 core

in vec4 Color;
in vec3 Normal;
in vec3 FragmentPosition;

out vec4 color;

uniform vec3 lightPosition;
uniform vec3 viewerPosition;

void main()
{
    vec4 ambientLight = vec4(0.1, 0.0, 0.3, 1.0);
    vec4 pointLight   = vec4(1.0, 1.0, 1.0, 1.0);

    vec3 normal = normalize(Normal);

    vec3 lightDirection = normalize(lightPosition - FragmentPosition);
    vec3 viewDirection = normalize(viewerPosition - FragmentPosition);

    float diffuseFactor = max(dot(lightDirection, Normal), 0.0);
    
    float specularFactor = 
    pow(max(dot(normalize(lightDirection + viewDirection),normal), 0.0), 32); /* h.normal */

    color = Color * ambientLight + diffuseFactor * Color * pointLight + Color * pointLight * specularFactor * 0.2f;

}
