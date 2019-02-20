#version 330 core

out vec4 color;

uniform bool sel;

void main()
{
    if(sel)
	{
		color = vec4(1.0f,0.0f,0.0f,1.0f);
	} else {
		color = vec4(0.0f,0.0f,1.0f,1.0f);
	}
}
