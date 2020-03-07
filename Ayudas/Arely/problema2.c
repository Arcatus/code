#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

struct nodo
{
	int id;
	char nombre[50];
	int numerodeOperaciones;
	int numerodeOperacionesRestantes;
	struct nodo *siguiente;
	struct nodo *anterior;
};

void introducirCliente(struct nodo **inicio, struct nodo **fin);
void listarClientes(struct nodo *inicio, struct nodo *fin);
void eliminarCliente(struct nodo **inicio, struct nodo **fin);
void realizarOperacion(struct nodo **inicio, struct nodo **fin);
void guardarLista(struct nodo *inicio, struct nodo *fin);
void leerLista(struct nodo **inicio, struct nodo **fin);

int contador_id = 0;

int main()
{
	int opcion;
	struct nodo *inicioCola = NULL;
	struct nodo *finCola = NULL;
	do
	{
		printf("MENU\n");
		printf("1. Introducir cliente a la fila\n");
		printf("2. Listar clientes en la fila\n");
		printf("3. Eliminar cliente de la fila\n");
		printf("4. Realizar operacion del cliente\n");
		printf("5. Guardar fila en archivo\n");
		printf("6. Leer fila de archivo\n");
		printf("7. Salir\n");

		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1: introducirCliente(&inicioCola,&finCola); break;
			case 2: listarClientes(inicioCola,finCola); break;
			case 3: eliminarCliente(&inicioCola,&finCola); break;
			case 4: realizarOperacion(&inicioCola,&finCola); break;
			case 5: guardarLista(inicioCola,finCola); break;
			case 6: leerLista(&inicioCola,&finCola); break;
		}
	} while( opcion != 7 );
}

void introducirCliente(struct nodo **inicio, struct nodo **fin)
{
	struct nodo *minodo = (struct nodo*) malloc( sizeof ( struct nodo ) );
	printf("Escribe el nombre del cliente\n");
	
	__fpurge(stdin);
	fgets(minodo->nombre,50,stdin);
	minodo->nombre[ strlen( minodo->nombre ) - 1 ] = 0;

	printf("Introduce el numero de operaciones\n");
	scanf("%d",&minodo->numerodeOperaciones);
	minodo->numerodeOperacionesRestantes = minodo->numerodeOperaciones;
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
}

void listarClientes(struct nodo *inicio, struct nodo *fin)
{
	struct nodo *temporal = fin;
	while( temporal != NULL && temporal->anterior != NULL )
	{
		printf("\n%d: %s, %d operaciones, espera",temporal->id,temporal->nombre,temporal->numerodeOperaciones);
		temporal = temporal->anterior;
	}
	if ( temporal != NULL )
	{
		printf("\n%d: %s, %d operaciones, atendiendo, %d operaciones\n",
			temporal->id,temporal->nombre,temporal->numerodeOperaciones,temporal->numerodeOperaciones-temporal->numerodeOperacionesRestantes);
	}
	else
	{
		printf("\nLa fila esta vacia!\n\n");
	}
	printf("\n");
}

void eliminarCliente(struct nodo **inicio, struct nodo **fin)
{
	struct nodo *temporal=*inicio;
	printf("Ingresa el id del cliente a eliminar\n");
	int borrar;
	scanf("%d",&borrar);
	int fueBorrado=0;
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
				 if ( temporal == *fin ) 
				 {
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
	if ( fueBorrado == 0 ) 
	{
		printf("\nNo se encontro el id que ingreso!!\n");
	}
	printf("\n");
}

void realizarOperacion(struct nodo **inicio, struct nodo **fin)
{
	if ( *inicio != NULL && (*inicio)->numerodeOperacionesRestantes > 0 )
	{
		(*inicio)->numerodeOperacionesRestantes -= 1;
	}
	else if ( (*inicio) != NULL && (*inicio)->numerodeOperacionesRestantes == 0 )
	{
		if ( (*inicio)->siguiente != NULL )
		{
			*inicio = (*inicio)->siguiente;
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
}

void guardarLista(struct nodo *inicio, struct nodo *fin)
{
	struct nodo *temporal = inicio;
	printf("Ingresa el nombre del archivo, no mas de 30 caracteres\n");
	char nombre[30];
	scanf("%s",nombre);
	FILE *archivo = fopen(nombre,"wt");
	while( temporal != NULL )
	{
		fprintf(archivo, "%d %s %d %d\n",
			temporal->id, temporal->nombre, temporal->numerodeOperaciones, temporal->numerodeOperacionesRestantes);
		temporal = temporal->siguiente;
	}
	fclose(archivo);
}

void leerLista(struct nodo **inicio, struct nodo **fin)
{
	printf("Ingresa el nombre del archivo a leer de mas de 30 caracteres\n");
	char nombre[30];

	__fpurge(stdin);

	scanf("%s",nombre);
	FILE *archivo = fopen(nombre,"rt");
	if ( archivo == NULL )
	{
		printf("\nEl archivo no existe!!\n\n");
		return;
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
				&temporal->id, temporal->nombre, &temporal->numerodeOperaciones, &temporal->numerodeOperacionesRestantes  ) != EOF )
	{
		struct nodo *minodo = (struct nodo*) malloc( sizeof ( struct nodo ) );
		minodo->id = temporal->id;
		strcpy(minodo->nombre,temporal->nombre);
		minodo->numerodeOperaciones = temporal->numerodeOperaciones;
		minodo->numerodeOperacionesRestantes = temporal->numerodeOperacionesRestantes;
		if ( *inicio == NULL && *fin == NULL )
		{
			*inicio = minodo;
			*fin = minodo;
			minodo->siguiente = NULL;
			minodo->anterior = NULL;
		}
		else
		{
			struct nodo *temporal = *inicio;
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
}
