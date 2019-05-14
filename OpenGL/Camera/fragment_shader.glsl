#version 330 core

in vec4 Color;
in vec3 Normal;
in vec3 FragmentPosition;

out vec4 color;

uniform vec3 lightPosition;

void main()
{
    vec4 ambientLight = vec4(1.0, 1.0, 1.0, 1.0);
    vec4 pointLight   = vec4(1.0, 1.0, 1.0, 1.0);

    vec3 lightDirection = normalize(lightPosition - FragmentPosition);

    float d = distance(lightPosition, FragmentPosition);

    float diffuseFactor = max(dot(lightDirection, Normal), 0.0);

    color = Color * ambientLight;
    
}
