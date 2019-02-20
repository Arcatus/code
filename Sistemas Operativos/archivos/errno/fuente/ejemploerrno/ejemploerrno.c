#include "ejemploerrno.h"

int main(void)
{
     if(open("no existe",O_RDONLY)==-1)
     {
     	fprintf(stderr,"error %i\n",errno);
     }
     return(0);
}