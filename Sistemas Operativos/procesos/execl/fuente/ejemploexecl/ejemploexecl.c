#include "ejemploexecl.h"

int main(void)
{
     printf("\aEjecutando ls\n");
     execl("/bin/ls","ls","-FRal",NULL);
     perror("Fallo el execl para correr ls\n");
     return(errno);
}
