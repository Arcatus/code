#include "ejemplofcntl.h"

int main(int argc, char** argv)
{
     int da;
     if(argc!=3)
     {
          puts("\aUso:\n");
          printf("%s archivo [r w rw a]\n",argv[0]);
          exit(1);
     }
     if((da=abrirarchivo(argv[1],argv[2]))==-1)
     {
	  perror("\aNo pude abrir\n");
	  fprintf(stderr,"errno %i \n",errno);
	  exit(errno);
     }else
     {
	  printf("Archivo %s abierto con exito\n",argv[1]);
     }
     estadoarchivo(da);
     return 0;
}
