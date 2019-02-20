#include "copiarchivo.h"

int TAMBUF;

int main(int argc, char** argv)
{
     int da1, da2, codret;
     if(argc!=4)
     {
          fprintf(stderr,"Uso:\n");
          fprintf(stderr,"%s archivo1 archivo2 BUFFER\n",argv[0]);
          fprintf(stderr,"\t archivo1: archivo a copiar\n");
          fprintf(stderr,"\t archivo2: archivo copiado\n");
          fprintf(stderr,"\t BUFFER: tamaño del buffer\n");
	     exit(1);
     }
     if(!strcmp(argv[1],argv[2]))
     {
	  fprintf(stderr,"archivo1 debe ser distino a archivo2\n");
	  exit(2);
     }
     if((TAMBUF=atoi(argv[3]))<=0)
     {
	  fprintf(stderr,"El tamaño del BUFFER debe ser mayor a CERO\n");
	  exit(3);
     }
     if((da1=open(argv[1],O_RDONLY))<0)
     {
	  fprintf(stderr,"\aNo pude abrir %s\n",argv[1]);
	  perror("para lectura\n");
	  exit(4);
     }
     if((da2=creat(argv[2],PERM))<0)
     {
	  fprintf(stderr,"\aNo pude abrir %s\n",argv[2]);
	  perror("para escritura\n");
	  exit(5);
     }
     if((codret=copiarchivo(da1,da2))<0)
     {
	  fprintf(stderr,"\aNo pude hacer la copia\n");
	  exit(codret);
     }
     if((close(da1))<0)
     {
	  
	  fprintf(stderr,"\aNo pude cerrar %s\n",argv[1]);
	  perror("despues de leer\n");
	  exit(6);
     }
     if((close(da2))<0)
     {
	  
	  fprintf(stderr,"\aNo pude cerrar %s\n",argv[2]);
	  perror("despues de escribir\n");
	  exit(7);
     }
     return(0);
}
