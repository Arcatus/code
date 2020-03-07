#include <stdio.h>

int main()
{
	FILE *archivo = fopen("texto.txt","r+");
 	
 	if ( archivo != NULL ) {

 		char palabra[10];

 		float v;

		while( fscanf(archivo,"%s %f",palabra,&v) != EOF ) {
			printf("%s %f\n",palabra,v);
		}
		fclose(archivo);
 	}
}