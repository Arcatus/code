//este es con argumentos de programa

#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;
  printf("Este programa despliega lo que escribiste en la linea de comandos.\n");
  printf("Tu linea de comandos tuvo %d palabras.\n", argc);
  printf("Estas son las palabras de tu linea de comando.\n");
  
  for(i=0; i<argc; i=i+1)
    {
      printf("argv[%d] vale %s\n", i, argv[i]);
    }
}