#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMCUBICULOS 10
#define TAMNOMBRE 51

char* dime(int);
int elimina(int);
int agrega(char*,int);