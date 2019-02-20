#include "mils.h"

int mils(char* nombre)
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
               printf("%s\n",entradadirectorio->d_name);
          }
     }
     if(closedir(directorio)==-1)
     {
          fprintf(stderr,"\aNo pude cerrar el directorio %s",nombre);
          perror("\n");
          return(-1);
     }
     return(0);
}