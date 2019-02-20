#include "ejemplofcntl.h"

void estadoarchivo(int archides)
{
     int arg1, mudo;
     if((arg1=fcntl(archides,F_GETFL,mudo))==-1)
     {
          perror("\a estado archivo fallo\n");
          exit(3);
     }
     printf("Descriptor de archivo %i:\n",archides);
     if(arg1 & O_WRONLY)
     {
          printf("Solo para escritura\n");	  
     }else if(arg1 & O_RDWR)
     {
	  printf("lectura-escritura\n");	  
     }else
     {
	  printf("Solo para lectura\n");
     }
     if(arg1 & O_APPEND)
     {
	  printf("Bandera de agregar encendida\n");
     }
     if(arg1 & O_CREAT)
     {
	  printf("Bandera de crear encendida \n");
     }
}
