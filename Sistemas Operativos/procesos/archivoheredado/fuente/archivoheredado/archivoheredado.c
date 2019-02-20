#include "archivoheredado.h"
#include "error.h"

int main(void)
{
   pid_t pid;
   int descriptorarchivo;
   char buffer[10];
   if((descriptorarchivo = open("datos",O_RDONLY))<0)
      error("Fallo el open");
   read(descriptorarchivo,buffer,10);
   imprimeposicion("Antes del fork",descriptorarchivo);
   if ((pid=fork())< 0) {
      error("fork fallo");
   }else if (!pid) {
      imprimeposicion("Antes que lea el hijo", descriptorarchivo);
      read(descriptorarchivo,buffer,10);
      imprimeposicion("Despues que leyo el hijo",descriptorarchivo);
      close(descriptorarchivo);
   } else {
      imprimeposicion("Padre antes de esperar", descriptorarchivo);
      wait(NULL);
      imprimeposicion("Padre despues de esperar", descriptorarchivo);
   }
   return(0);
}
