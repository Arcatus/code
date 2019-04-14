#include "error.h"

void error(char* mensaje)
{
	fprintf(stderr, "\a");
	perror(mensaje);
	exit((errno)?errno:-1);
}