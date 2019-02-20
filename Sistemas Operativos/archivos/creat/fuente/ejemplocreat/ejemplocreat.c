#include "ejemplocreat.h"

int main(void)
{
     int desarchivo;
     char nombrearchivo[]="nuevo";
     if((desarchivo=creat(ARCHIVO,PERMISOS))==-1)
     {
          printf("\a No pude crear el archivo %s\n",ARCHIVO);
          exit(1);
     }
     return 0;
}
