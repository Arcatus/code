#include "ejemploread2.h"

int main(void)
{
     int da, conta;

     char buffer[TAMBUF];
     long total=0;
     if((da=open(ARCHIVO,O_RDONLY))<0)
     {
 	     printf("Error al abrir %s\n",ARCHIVO);
	     exit(1);
     }
     for(;(conta=read(da,buffer,TAMBUF))>0);
     	total+=conta;
     printf("Total de caracteres de %s:%li\n",ARCHIVO,total);
     return (0);
}
