#include "pruebamieco.h"

int main(void)
{
   char* arg[] = {"mieco","Hola","mundo","¿","Como","taz","?",NULL};
   printf("\aEjecutandomieco\n");
   execvp(arg[0],arg);
   perror("Fallo en el execvp para correr mieco\n");
   return(errno);
}