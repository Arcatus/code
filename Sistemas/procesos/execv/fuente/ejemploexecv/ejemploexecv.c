#include "ejemploexecv.h"
 
int main(void)
{
 	char* arg[]={"ls","-FRal",NULL};
    printf("\aEjecutando ls\n");
    execv("/bin/ls",arg);
    perror("Fallo el execv para correr ls\n");
    return(errno);
}