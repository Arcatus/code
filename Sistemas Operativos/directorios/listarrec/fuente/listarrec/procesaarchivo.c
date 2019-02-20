#include "listarrec.h"

int procesaarchivo(const char *archivo, const struct stat *metadata,int tipo)
{
     switch(tipo)
     {
     	FTW_NS:
     		break;
     	default:
     			printf("%i\t%-s\n",metadata->st_ino,archivo);
     		break;
     }
     return 0;
}