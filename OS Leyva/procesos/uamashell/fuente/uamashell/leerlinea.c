/*********************************************
autor: hpl 
modificaci'on: mn-7-10 (2143036080)
Descripci'on:
Llena el buffer con los caracteres le'idos de 
la entrada est'andar cuando encuentra salto de 
l'inea coloca nulo al final del buffer.

**********************************************/

#include "uamashell.h"

int leerlinea(char* prompt, char* bufferentrada)
{
	int caracter, contador;

	printf("%s", prompt); 

	for (contador=0;;) { 

		if (((caracter=getchar())==EOF)) {
		   return(EOF);
		}else if (caracter=='q') {
			return(EOF);
		}
		if (contador < MAXBUF) { // verificamos que no exedemos el m'aximo de 512
			bufferentrada[contador++]=caracter; // se indexa caracter en buffer[0] luego se incrementa
		}
		if (caracter=='\n' && contador < MAXBUF) {
		   bufferentrada[contador]='\0'; // Finalizamos con car'acter nulo una vez apretamos enter
		   return(contador); // regresamos la cantidad de caracteres v'alidos le'idos 
		}
		if (caracter=='\n') { // Si enter y contador > MAXBUF buffer insuficiente
		   printf("linea muy larga.\n");
		   contador = 0;
		   printf("%s",prompt);
		}
	}
}