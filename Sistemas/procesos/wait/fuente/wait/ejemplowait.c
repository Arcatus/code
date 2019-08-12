#include "ejemplowait.h"
#include "error.h"

int main(void)
{
   pid_t pid;
   int estado, estado_salida;
   if ((pid=fork()) < 0) {
      error("fork fall");
   }
   if (!pid) {
      sleep(4);
      exit(5);
   }
   if (wait(&estado)<0)
      error("fallo el wait");
   if ((estado & 0xFF)) {
      printf("Alguno de los bits menos signigicativo no es 0\n");
   } else {
      estado_salida=estado>>8;
      estado_salida &= 0xFF;
      printf("Estado de salida de %i fue %i\n",pid,estado_salida);
   }
   return(0);
}
