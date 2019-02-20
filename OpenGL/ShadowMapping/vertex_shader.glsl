#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec3 normal;

out vec4 Color;
out vec3 Normal;
out vec3 FragmentPosition;
out vec4 FragmentPositionLightSpace;

uniform mat4 model;
uniform mat4 vp;
uniform mat4 lightMvp;

void main()
{
    vec4 globalPosition = model * vec4(position, 1.0);

    Color = color;
    Normal = normal;
    FragmentPosition = vec3(globalPosition);
    FragmentPositionLightSpace = lightMvp * globalPosition;

    gl_Position = vp * globalPosition;
}
