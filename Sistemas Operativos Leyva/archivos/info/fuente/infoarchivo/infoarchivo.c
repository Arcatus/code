#include "infoarchivo.h"

int main(int argc, char** argv)
{
     if(argc!=2)
     {
          fprintf(stderr,"\a Error uso:\n");
	  fprintf(stderr,"%s archivo\n",argv[0]);
	  exit(1);
     }
     if(datosarchivo(argv[1]==-1))
     {
	  fprintf(stderr,"Información de %s No disponible\n",argv[1]);
	  exit(errno);
     }
     return(0);
}
