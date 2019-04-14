#include <unistd.h>
#include <dirent.h>
#include "miinodo.h"

int miinodo(char* nombre, char* archivo)
{
     struct dirent* entradadirectorio;
     DIR* directorio;

     if((directorio=opendir(nombre))==NULL)
     {
          fprintf(stderr,"\aNo pude abrir el directorio %s", nombre);
          perror("\n");
          return(-1);
     }
     while(entradadirectorio=readdir(directorio))
     {
     	if(entradadirectorio -> d_ino!=0)
          {
               if(!strncmp(archivo,entradadirectorio->d_name,strlen(archivo)))
               {                    
                    return(entradadirectorio->d_ino);
               }
          }
          if(closedir(directorio)==-1)
          {
               fprintf(stderr, "\aNo pude cerrar el directorio %s",nombre);
               perror("\n");
               return(-1);
          }
     }
     return(0);
}
