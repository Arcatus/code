#version 330 core
in float ID;
out vec4 pixel;

uniform float color;

void main()
{
	switch(int(ID))
	{
		case 0:
			pixel = vec4(color-0.2f,color+0.2f,color+0.5f,1.0f);
			break;
		case 1:
			pixel = vec4(color+0.4f,color-0.2f,color+0.1f,1.0f);
			break;
		case 2:
			pixel = vec4(color-0.1f,color+0.4f,color+0.0f,1.0f);
			break;
		case 3:
			pixel = vec4(color+0.5f,color-0.4f,color-0.2f,1.0f);
			break;
		case 4:
			pixel = vec4(color-0.3f,color+0.1f,color-0.5f,1.0f);
			break;	
		default:
			pixel = vec4(color+0.2f,color-0.3f,color+0.2f,1.0f);
			break;
	}
}