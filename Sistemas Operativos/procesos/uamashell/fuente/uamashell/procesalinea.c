/*********************************************
autor: hpl 
modificaci'on: mn-7-10 (2143036080)
Descripci'on:
Tokeniza el buffer, verificando que estemos
dentro del rango de argumentos v'alido una 
vez llega al final procede a ejecutar execvp.

**********************************************/

#include "uamashell.h"

void procesalinea(char* bufferentrada) 
{
   char buffertoken[2*MAXBUF];

   char* arg[MAXARG+1];
   char* apuntador = bufferentrada;
   char* token = buffertoken;
   
   int tipotoken;
   int contador;
   int tipo;

   for(contador=0;;) {
      switch(tipotoken = dametoken(&arg[contador],&apuntador,&token))
      {
         case ARG:
         	if(contador < MAXARG) // verificamos no procesar m'as del m'aximo 512 argumentos.
         		contador++;
         	break;
         // Si terminamos de procesar los argumentos procedemos a ejecutar arg[0].
         // EOL, PUNTOYCOMA, AMPERSAND se ejecutan en un mismo case solo se verifica el plano.
         case EOL:
         case PUNTOYCOMA:
         case AMPERSAND:
         	tipo = (tipotoken==AMPERSAND)?SEGUNDOPLANO:PRIMERPLANO; 
            if(contador) {
               arg[contador]=NULL; // Colocamos al final de la lista NULL para que execvp pueda funcionar.
               sistema(arg,tipo);  // ejecutamos comando en arg[0] con argumentos arg.
            }
            if(tipotoken==EOL) // Nada que hacer salimos.
               return;
            contador = 0;
         break;
      }
   }
}