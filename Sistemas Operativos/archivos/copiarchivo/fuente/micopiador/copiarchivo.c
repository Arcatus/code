#include "copiarchivo.h"

extern int TAMBUF;

int copiarchivo(int da1, int da2)
{
     int archient, archisal, nleidos;
     char* buffer;
     if(da1 < 0)
     {
          return(-1);
     }
     if(da2 < 0)
     {
	  return(-2);
     }
     if((buffer = (char*)calloc(TAMBUF,sizeof(char))) == NULL)
     {
	  fprintf(stderr,"No hay memoria para el buffer\n");
	  return(-3);
     }
     while((nleidos=read(da1,buffer,TAMBUF)) > 0)
     {
	  if(write(da2,buffer,nleidos) < nleidos)
	  {
               return(-3);
	  }
     }
     return(0);
}
