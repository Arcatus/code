/*********************************************
autor: hpl 
modificaci'on: mn-7-10 (2143036080)
Descripci'on:
Verifica el tipo de token devuelve un entero
que procesalinea empleara para identificarlo.
**********************************************/

#include "uamashell.h"

int dametoken(char** apuntadorsalida, char** apuntador, char** token)
{
   int tipo;
   *apuntadorsalida=*token; 
   for(;**apuntador==' ' || **apuntador=='\t';(*apuntador)++) // saltamos espacios
         ;
   *(*token)++ = **apuntador; // asignamos primer caracter v'alido a token e incrementamos su direcci'on
   switch(*(*apuntador)++) {
      case '\n':
         tipo=EOL;
         break;
      case '&':
      	tipo=AMPERSAND;
      	break;
      case ';':
      	tipo=PUNTOYCOMA;
      	break;
      default:
      	tipo=ARG;
      	while(esargumento(**apuntador)) // tokenizamos verificando que sea v'alido
      		*(*token)++=*(*apuntador)++;
       	break; 
      }
   *(*token)++ = '\0'; // añadimos caracter nulo al buffertoken
   return(tipo);
}