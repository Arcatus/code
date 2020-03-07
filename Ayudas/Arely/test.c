#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE* archivo;

	archivo = fopen("texto.txt","r+");

	if ( archivo != NULL ) {
		printf("Archivo abierto con exito\n");

		char palabra[10];

		while( fscanf( archivo, "%s", palabra ) > 0 ) {
			printf("%s\n",palabra);
		}

		/*
		char str[] = { "cArLos" };

		for(int i=0; i<strlen(str); ++i) {
			if ( isupper( str[i] ) != 0 ) {
				printf("%c Es mayuscula\n",str[i]);
			}
			if ( islower( str[i] ) != 0 ) {
				printf("%c Es minuscula\n",str[i]);
			}
		}
		

		-> Escribir cadenas en archivos

		for(i=0; i<n_files;i++) {
        	fprintf(archivo, "%d\n", temps[i]);
      	}
      	-> Leer cadenas desde archivos

      	for(i=0;i<n_files;i++){
        	fscanf(archivo,"%d\n", &temps[i]);
      	}

		-> Leer chars en archivo

		char ch;

		while ( (ch = fgetc(archivo) ) != EOF) {
            printf("%c", ch);
        }

		-> Escribir chars en archivo

		int i;

		for(i=0; i<10; ++i) {
			fputc(i+'0',archivo);
		}
		*/
		fclose(archivo);
	} else {
		printf("No se pudo abrir el archivo\n");
	}
}	