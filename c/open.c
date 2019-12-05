#include <stdio.h>

int main()
{

	//char a[10] = "miarchivo"; // este tu lo solicitas

	char a[10];

	printf("Ingresa el nombre de tu archivo:\n");
	scanf("%s",a);

	char b[10] = ".txt";

	char buf[21];
	snprintf(buf, sizeof buf, "%s%s", a, b);

	FILE *fichero = fopen( buf, "w" );
	
	fprintf(fichero, "Hola mundo\n");

	fclose(fichero);

	return 0;
}