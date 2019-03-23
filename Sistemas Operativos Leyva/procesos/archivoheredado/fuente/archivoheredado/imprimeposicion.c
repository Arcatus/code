#include "archivoheredado.h"
#include "error.h"

void imprimeposicion(char* texto, int descriptorarchivo)
{
   long posicion;
   if((posicion=lseek(descriptorarchivo,0l,1))<0)
      error("lseek fallo\n");
   printf("%s:%ld\n",texto,posicion);
}

