#include <iostream>
#include <cstdlib>
#include <FreeImage.h>

#include "texture.h"

GLuint createTextureObject(const GLchar* filename)
{
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename);

	if(format == FIF_UNKNOWN)
	{
		std::cerr << "Unknow format." << std::endl;	
		exit(0);
	}

	FIBITMAP* bitmap = FreeImage_Load(format, filename);

	GLint bpp = FreeImage_GetBPP(bitmap);

	FIBITMAP* bitmap32 = NULL;
		
	if (bpp == 32)
	{
		bitmap32 = bitmap;
	} else {
		bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
		FreeImage_Unload(bitmap);
	}

	GLuint texture;

	glGenTextures(1,&texture);
	
	glBindTexture(GL_TEXTURE_2D,texture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, FreeImage_GetWidth(bitmap32),
		FreeImage_GetHeight(bitmap32), 0, GL_BGRA, GL_UNSIGNED_BYTE,FreeImage_GetBits(bitmap32));

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);	

	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D,0);

	FreeImage_Unload(bitmap32);

	return texture;
}