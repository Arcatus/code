//listas dinamicas que insertan valores al primer lugar de la lista
//recordar que se imprimer al reves

#include <stdio.h>
#include <stdlib.h>

typedef struct def_dato
{
  int dato;
  struct def_dato *sig;
}tipodato;

void InsertaInicio(tipodato **inicio, int valor);
void Imprime(tipodato *inicio);
void Elimina(tipodato *inicio);


int main(void)
{
  tipodato *Primero=NULL;
  int numero;
  printf("Introduzca numeros separados por enter y una letra al terminar:\n");
  while(scanf("%d", &numero)==1)
    InsertaInicio(&Primero, numero);
  printf("Los numero introducidos son:\n");
  Imprime(Primero);
  Elimina(Primero);
}


void InsertaInicio(tipodato **inicio, int valor)
{
  tipodato *temp;
    temp = (tipodato *)malloc(sizeof(tipodato));
  temp->dato = valor;
  temp->sig = *inicio;
  *inicio=temp;
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