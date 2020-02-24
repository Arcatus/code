#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo
{
	int id;
	char nombre[30];
	int numeroHojas;
	int restantes;
	struct nodo *siguiente;
	struct nodo *anterior;
};

int introducirDocumento(struct nodo **inicio, struct nodo **fin);
int listarCola(struct nodo *inicio, struct nodo *fin);
int eliminarCola(struct nodo **inicio, struct nodo **fin);
int imprimirDocumento(struct nodo **inicio, struct nodo **fin);
int guardarCola(struct nodo *inicio, struct nodo *fin);
int leerCola(struct nodo **inicio, struct nodo **fin);

int contador_id = 0;

int main()
{
	int opcion;

	struct nodo *inicioCola = NULL;
	struct nodo *finCola = NULL;
	
	do
	{
		printf("1. Introducir documento a la cola de impresion\n");
		printf("2. Listar trabajos en la cola de impresion\n");
		printf("3. Eliminar trabajo de la cola de impresion\n");
		printf("4. Imprimir documento\n");
		printf("5. Guardar cola en archivo\n");
		printf("6. Leer cola de archivo\n");
		printf("7. Salir\n");

		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1: introducirDocumento(&inicioCola,&finCola); break;
			case 2: listarCola(inicioCola,finCola); break;
			case 3: eliminarCola(&inicioCola,&finCola); break;
			case 4: imprimirDocumento(&inicioCola,&finCola); break;
			case 5: guardarCola(inicioCola,finCola); break;
			case 6: leerCola(&inicioCola,&finCola); break;
		}
	} while( opcion != 7 );
}

int introducirDocumento(struct nodo **inicio, struct nodo **fin)
{
	struct nodo *minodo = (struct nodo*) malloc( sizeof ( struct nodo ) );

	printf("Escribe el nombre del documento\n");
	scanf("%s",minodo->nombre);
	printf("Introduce el numero de hojas\n");
	scanf("%d",&minodo->numeroHojas);

	minodo->restantes = minodo->numeroHojas;
	minodo->id = ++contador_id;

	if ( *inicio == NULL && *fin == NULL )
	{
		*inicio = minodo;
		*fin = minodo;
		minodo->siguiente = NULL;
		minodo->anterior = NULL;
	}
	else
	{
		struct nodo *temporal;
		temporal = *inicio;

		while( temporal->siguiente != NULL ) 
		{
			temporal = temporal->siguiente;
		}

		minodo->siguiente = NULL;
		
		minodo->anterior = temporal;
		temporal->siguiente = minodo;

		*fin = minodo;
	}
	printf("\n");

	return 0;
}

int listarCola(struct nodo *inicio, struct nodo *fin)
{
	struct nodo *temporal = fin;

	while( temporal != NULL && temporal->anterior != NULL )
	{
		printf("\n%d: %s, %d hojas, espera",temporal->id,temporal->nombre,temporal->numeroHojas);

		temporal = temporal->anterior;
	}

	if ( temporal != NULL )
	{
		printf("\n%d: %s, %d hojas, imprimiendo, %d hojas impresas\n",
			temporal->id,temporal->nombre,temporal->numeroHojas, temporal->numeroHojas - temporal->restantes);
	} 
	else
	{
		printf("\nLa cola esta vacia!\n\n");
	}
	printf("\n");
}

int eliminarCola( struct nodo **inicio, struct nodo **fin)
{	
	struct nodo *temporal = *inicio;

	printf("Ingresa el id del documento a eliminar\n");

	int borrar;

	scanf("%d",&borrar);

	int fueBorrado = 0;

	if ( temporal != NULL )
	{
		while( temporal != NULL )
		{
			if ( temporal->id == borrar ) 
			{
				 if ( temporal->anterior != NULL )
				 {
				 	temporal->anterior->siguiente = temporal->siguiente;
				 }
				 if ( temporal->siguiente != NULL )
				 {
				 	temporal->siguiente->anterior = temporal->anterior;
				 }

				 if ( temporal == *inicio )
				 {
				 	*inicio = temporal->siguiente;
				 }
				 if ( temporal == *fin ) {
				 	*fin = temporal->anterior;
				 }
				 
				 free(temporal);
				 temporal = NULL;
				 fueBorrado = 1;
				 break;
			}
			temporal = temporal->siguiente;
		}
	}
	if ( fueBorrado == 0 ) {
		printf("\nNo se encontro el indice que ingreso!!\n");
	}
	printf("\n");
	return 0;
}

int imprimirDocumento(struct nodo **inicio, struct nodo **fin)
{
	if ( *inicio != NULL && (*inicio)->restantes > 0 )
	{
		(*inicio)->restantes -= 1;
	}
	else if ( (*inicio) != NULL && (*inicio)->restantes == 0 )
	{
		if ( (*inicio)->siguiente != NULL )
		{
			(*inicio) = (*inicio)->siguiente;
			(*inicio)->anterior = NULL;
		}
		else 
		{
			free(*inicio);
			*inicio = NULL;
			*fin = NULL;
		}
	}
	printf("\n");
	return 0;
}

int guardarCola(struct nodo *inicio, struct nodo *fin)
{
	struct nodo *temporal = inicio;

	printf("Ingresa el nombre del archivo\n");

	char nombre[30];

	scanf("%s",nombre);

	FILE *archivo = fopen(nombre,"wt");

	while( temporal != NULL )
	{
		fprintf(archivo, "%d %s %d %d\n",
			temporal->id, temporal->nombre, temporal->numeroHojas, temporal->restantes);
		temporal = temporal->siguiente;
	}
	fclose(archivo);

	return 0;
}

int leerCola(struct nodo **inicio, struct nodo **fin)
{
	printf("Ingresa el nombre del archivo\n");

	char nombre[30];

	scanf("%s",nombre);

	FILE *archivo = fopen(nombre,"rt");

	if ( archivo == NULL )
	{
		printf("\nEl archivo no existe!!\n\n");
		return 0;
	}

	struct nodo *temporal = (struct nodo*) malloc( sizeof ( struct nodo ) );

	struct nodo *eraser;

	while( *inicio != NULL )
	{
		eraser = (*inicio)->siguiente;
		if ( eraser != NULL )
		{
			free(eraser->anterior);
			eraser->anterior = NULL;
		}
		*inicio = eraser;
	}

	*fin = NULL;

	while( fscanf(archivo,"%d %s %d %d\n",
				&temporal->id, temporal->nombre, &temporal->numeroHojas, &temporal->restantes  ) != EOF )
	{
		struct nodo *minodo = (struct nodo*) malloc( sizeof ( struct nodo ) );

		minodo->id = temporal->id;
		strcpy(minodo->nombre,temporal->nombre);
		minodo->numeroHojas = temporal->numeroHojas;
		minodo->restantes = temporal->restantes;

		if ( *inicio == NULL && *fin == NULL )
		{
			*inicio = minodo;
			*fin = minodo;
			minodo->siguiente = NULL;
			minodo->anterior = NULL;
		}
		else
		{
			struct nodo *temporal;
			temporal = *inicio;

			while( temporal->siguiente != NULL )
			{
				temporal = temporal->siguiente;
			}

			minodo->siguiente = NULL;
			
			minodo->anterior = temporal;
			temporal->siguiente = minodo;

			*fin = minodo;
		}
	}
	fclose(archivo);
	return 0;
}