#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec3 normal;

uniform mat4 model;
uniform mat4 mvp;
uniform vec3 lightPosition;

out vec4 Color;

void main()
{	
	// Position
    gl_Position = mvp * vec4(position, 1.0);

    // Light
    vec4 ambientLight = vec4(0.20, 0.2, 0.2, 1.0);
	vec4 diffuseLight = vec4(0.25, 0.3, 0.4, 1.0);

	vec3 lightDirection = normalize(lightPosition - vec3(model * vec4(position, 1.0)));

	float diffuseFactor = max(dot(lightDirection, normal), 0.0);

    Color = color * ambientLight + color * diffuseLight * diffuseFactor;
}
