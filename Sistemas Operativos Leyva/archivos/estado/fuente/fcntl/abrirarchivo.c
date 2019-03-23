#include "ejemplofcntl.h"

int abrirarchivo(char* nombre, char* modo)
{
     int da;
     if(!strcmp(modo,"r"))
     {
          return open(nombre,O_RDONLY);
     }else if(!strcmp(modo,"w"))
     {
          return open(nombre,O_WRONLY);
     }else if(!strcmp(modo,"rw"))
     {
	  return open(nombre,O_RDWR);
     }else if(!strcmp(modo,"a"))
     {
	  return open(nombre,O_WRONLY | O_APPEND);
     }else if(!strcmp(modo,"c"))
     {
	  return open(nombre,O_WRONLY | O_CREAT,0644);
     }else
     {
	  return(-1);
     }
}
