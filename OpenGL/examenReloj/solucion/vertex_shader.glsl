#version 330 core

layout (location = 0) in vec3 position;

uniform bool isHandClock;
uniform vec3 displacement;

void main()
{
    if(sel)
    {
        gl_Position = vec4(position, 1.0);
    }
    else
    {
        gl_Position = vec4(0.05 * position + displacement, 1.0);
    }
}
