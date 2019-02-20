#include "entradasalida.h"

int main(void)
{
     int leidos;
     char buffer[TAMBUFFER];
     while((leidos=read(0,buffer,TAMBUFFER))>0)
     {
          write(1,buffer,leidos);
     }
     return(0);
}
