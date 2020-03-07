#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

int   cuentaPalabras(char palabra[]);
int cuentaminusculas(char palabra[]);
int cuentamayusculas(char palabra[]);
int     cuentaletras(char palabra[]);
int   cuentaespacios(char palabra[]);

int main()
{
	char palabra[20];

	printf("Ingresa el nombre del archivo\n");

	__fpurge(stdin);

	scanf("%s",palabra);

	FILE *archivo = fopen( palabra, "rt" );

	if ( archivo != NULL )
	{
		fclose(archivo);
		
		printf("numero de palabras\n");
		int numerodepalabras = cuentaPalabras( palabra );
		printf("%d\n", numerodepalabras );

		printf("numero de minusculas\n");
		int numerodeminusculas = cuentaminusculas( palabra );
		printf("%d\n", numerodeminusculas );

		printf("numero de mayusculas\n");
		int numerodemayusculas = cuentamayusculas( palabra );
		printf("%d\n", numerodemayusculas );

		printf("numero de letras\n");
		int numerodeletras = cuentaletras( palabra );
		printf("%d\n", numerodeletras );

		printf("numero de espacios\n");
		int numerodeespacios = cuentaespacios( palabra );
		printf("%d\n", numerodeespacios );
	}

	return 0;
}

int cuentaPalabras(char palabra[])
{ 
	FILE *archivo = fopen( palabra, "rt" );

	char arreglo[20];
	int numerodepalabras = 0;
	while( (fscanf( archivo, "%s", arreglo )) != EOF )
	{
		numerodepalabras+=1;
	}
	fclose(archivo);
	return numerodepalabras;
}

int cuentaminusculas(char palabra[])
{	
	FILE *archivo = fopen( palabra, "rt" );
	char arreglo[20];
	int numerodeminusculas = 0;
	while( (fscanf( archivo, "%s", arreglo )) != EOF )
	{ 
		int i;
		for( i=0; i<strlen(arreglo); i++ ) 
		{
			if( islower( arreglo[i]) != 0 )
			{
				numerodeminusculas++;
			}
		}
	}
	fclose(archivo);
	return numerodeminusculas;
}

int cuentamayusculas(char palabra[])
{
	FILE *archivo = fopen( palabra, "rt" );
	char arreglo[20];
	int numerodemayusculas = 0;
	while( (fscanf( archivo, "%s", arreglo )) != EOF )
	{ 
		int i;
		for( i=0; i<strlen(arreglo); i++ ) 
		{
			if( isupper( arreglo[i]) != 0 )
			{
				numerodemayusculas++;
			}
		}
	}
	fclose(archivo);
	return numerodemayusculas;
}

int cuentaletras(char palabra[])
{
	int numerodeletras = 0;
	numerodeletras = cuentaminusculas(palabra) + cuentamayusculas(palabra);
	return numerodeletras;
}

int cuentaespacios(char palabra[])
{
	FILE *archivo = fopen( palabra, "rt" );
	char c;
	int numerodeespacios = 0;
	
	while( ( c = fgetc( archivo )) != EOF )
	{ 
		if( c == ' ' )
		{
			numerodeespacios++;
		}
	}
	fclose(archivo);
	return numerodeespacios;
}