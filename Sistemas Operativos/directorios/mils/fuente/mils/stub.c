#include "mils.h"

int main(int argc, char** argv)
{
     if(argc!=2)
     {
          fprintf(stderr,"Uso:\n");
          fprintf(stderr,"directorio\n");
          exit(1);
     }
     if(mils(argv[1])==-1)
     {
          fprintf(stderr, "Fallo mils\n");
          exit(2);
     }
     return (0);
}