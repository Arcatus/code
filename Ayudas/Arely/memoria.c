#include<stdio.h>
#include<stdlib.h>

void Lee(int Lista[], int elementos);
void Imprime(int Lista[], int elementos);

int main()
{
  int cantidad;
  int *arreglo;
  printf("Cuantos numero vas a introducir: ");
  scanf("%d", &cantidad);

  arreglo = (int*) malloc( sizeof( int ) * cantidad);
  Lee(arreglo, cantidad);
  Imprime(arreglo, cantidad);
  free(arreglo);
}

void Lee(int Lista[], int elementos)
{
  int i;
  for(i=0; i<elementos; i++) {
      printf("introduzca el numero %d: ", i+1);
      scanf("%d", &Lista[i]);
    }
}

void Imprime(int Lista[], int elementos)
{
  int i;
  for(i=0; i<elementos; i++)
    printf("%d\n", Lista[i]);
}