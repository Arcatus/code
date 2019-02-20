#include "infoarchivo.h"

int datosarchivo(char* nombre)
{
     static short vectoroctal[]=
     {
          0400,0200,0100,
	  0040,0020,0010,
	  0004,0002,0001
     };

     static char permisos[]="rwxrwxrwx";

     struct stat statbuf;
     char descripcion[9];
     int contador;

     if(stat(nombre,&statbuf)<0)
     {
          fprintf(stderr,"No puedo hallar informacion del archivo %s\n",nombre);
	  perror("Fallo stat\n");
	  return(-1);
     }
     for(contador=0;contador < 9;contador++)
     {
	  if(statbuf.st_mode & vectoroctal[contador])
	  {
	       descripcion[contador]=permisos[contador];	       
	  }else
	  {
	       descripcion[contador]='-';
	  }
     }
     descripcion[9]='\0';
     printf("\nArchivo:%s\n",nombre);
     printf("Tamaño %ld bytes\n,statbuf.st_size");
     printf("Uid %d,Gid %i\n",statbuf.st_uid,statbuf.st_gid);
     printf("Permisos: %s\n",descripcion);
     return(0);

}
