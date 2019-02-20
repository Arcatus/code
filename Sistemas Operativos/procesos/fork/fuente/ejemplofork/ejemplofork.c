#include "ejemplofork.h"

int main(void)
{
     pid_t pid;
     printf("Un proceso para probar\nLlamado al fork\n");
     pid = fork();
     if(!pid)
     {
          printf("Soy el hijo");
     }else if(pid > 0)
     {
          printf("Soy el padre, mi hijo tiene pid %i\n",pid);
     }else
     {
          printf("Fallo el fork\n");
     }
     return(0);
}
