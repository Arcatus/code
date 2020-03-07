//listas dinamicas con funcion que inserta valores al final de la lista.
//funciones de borrar lista e imprimir lista

#include<stdio.h>
#include<stdlib.h>

typedef struct def_dato
{
  int dato;
  struct def_dato *sig;
}tipodato;

void InsertaFin(tipodato **inicio, int valor);
void Imprime(tipodato *inicio);
void Elimina(tipodato *inicio);


int main(void)
{
  tipodato * Primero=NULL;
  int numero;
  printf("Introduzca numeros separados por enter  y una letra al terminar:\n");
  while(scanf("%d", &numero)==1)
    InsertaFin(&Primero, numero);
  printf("Los numero introducidos son:\n");
  Imprime(Primero);
  Elimina(Primero);
}



void InsertaFin(tipodato **inicio, int valor)
{
  tipodato *temp, *temp2;
  temp=(tipodato *)malloc(sizeof(tipodato));
  temp->dato = valor;
  temp->sig = NULL;
  if(*inicio != NULL)
    {
      temp2 = *inicio;
      while(temp2->sig != NULL)
        temp2 = temp2->sig;
      temp2->sig = temp;
    }
  else
    *inicio = temp;
}

void Imprime(tipodato *inicio)
{
  tipodato *temp;
  temp = inicio;
  while(temp != NULL)
    {
      printf("%d\n", temp->dato);
      temp=temp->sig;
    }
}

void Elimina(tipodato *inicio)
{
  tipodato *temp;
  temp = inicio;
  while(temp != NULL)
    {
      inicio=inicio->sig;
      free(temp);
      temp = inicio;
    }
}