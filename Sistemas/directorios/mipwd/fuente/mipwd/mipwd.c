#include "mipwd.h"

char* mipwd(char* rutaactual)
{
     char directorio[TAMRUTA];

     if(getcwd(directorio,TAMRUTA)==NULL)
     {
          fprintf(stderr,"\aFallo getcwd");
          perror("\n");
          return(NULL);
     }
     strcpy(rutaactual,directorio);
     return(rutaactual);
}