#include "mipwd.h"

int main(void)
{
     char directorioactual[TAMRUTA];
     if(mipwd(directorioactual)==NULL)
     {
          fprintf(stderr,"No se puede hallar el directorio actual\n");
          exit(1);
     }
     printf("El directorio actual es %s\n",directorioactual);
     return (0);
}