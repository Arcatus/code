#include "ejemploperror.h"

int main(void)
{
     if(open("no existe",O_RDONLY)==-1)
     {
     	fprintf(stderr,"error %i\n",errno);
     	perror("No se puede abrir el archivo no existe:\n");
     	exit(1);
     	}
     return(0);
}