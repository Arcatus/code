#include "miinodo.h"

int main(int argc, char** argv)
{
     ino_t inodo;
     if(argc!=3)
     {
          fprintf(stderr,"Uso:\n");
          fprintf(stderr,"directorio archivo\n");
          exit(1);
     }
     if((inodo=miinodo(argv[1],argv[2]))==-1)
     {
          fprintf(stderr, "Fallo miinodo\n");
          exit(2);
     }else if(inodo)
     {
          printf("El inodo de %s es %i\n",argv[2],inodo);
     }else
     {
          printf("El archivo %s no se encuentra en el directorio%s\n",argv[2],argv[1]);
     }
     return (0);
}