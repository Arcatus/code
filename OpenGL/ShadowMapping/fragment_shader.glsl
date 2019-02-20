#version 330 core

in vec4 Color;
in vec3 Normal;
in vec3 FragmentPosition;
in vec4 FragmentPositionLightSpace;

out vec4 color;

uniform vec3 lightPosition;

uniform sampler2D depthSampler;

float getShadowFactor()
{
    vec3 position = vec3(FragmentPositionLightSpace) / FragmentPositionLightSpace.w;

    float bufferDepth = texture(depthSampler, vec2(position)).r;

    if(position.z > 1.0)
    {
        return 1.0;
    }

    if(position.z - 0.005 > bufferDepth)
    {
        return 0.0;
    }

    return 1.0;
}

void main()
{
    vec4 ambientLight = vec4(0.2, 0.2, 0.2, 1.0);
    vec4 pointLight   = vec4(1.0, 1.0, 1.0, 1.0);

    vec3 lightDirection = normalize(lightPosition - FragmentPosition);
    float diffuseFactor = max(dot(lightDirection, Normal), 0.0);

    float shadowFactor = getShadowFactor();

    color = Color * ambientLight + shadowFactor * diffuseFactor * Color * pointLight;
}
