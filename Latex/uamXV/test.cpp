#include <stdio.h>
#define HIGH_VALUE ((char *) 1)
#define LOW_VALUE ((char *) 0)
#define lduint(p) ((unsigned short)((((((char *)(p))[0])) << 8) | ((((char*)(p))[1]) & 0xFF)))

int main()
{
    char *aux = new char;
    *aux = 'a';
    printf("HIGH_VALUE: %lu\n",lduint());
    return 0;
}