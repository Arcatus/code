#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	int id;
	char nombre[30];
	struct nodo *ant;
	struct nodo *sig;
} tnodo;

void insertaCliente()
{

}

int main()
{
	int opcion;

	tnodo *inicioLista = NULL;

	do
	{
		printf("1. Añadir cliente\n");
		printf("2. Borrar Cliente\n");


		switch()
		{
			case 1: insertaCliente(&inicioLista); break;
			case 2:
			case 3:
		}

		scanf("%d",&opcion);

	}while( opcion != 5 )

}

void insertaCliente(tnodo **inicio)
{
	tnodo *temp = (tnodo*) malloc( sizeof( tnodo ) );

	if( *inicio != NULL ) 
	{
		
	}
	else 
	{
		*inicio = temp;
	}
}	