/*********************************************
autor: hpl 
modificaci'on: mn-7-10 (2143036080)
Descripci'on:
Verifica si el char es caracter especial.
**********************************************/

#include "uamashell.h"

bool esargumento(char c) {
   char* trabajo;
   char especial[] = {' ','\t','&',';','\n','\0'};
   for (trabajo=especial;*trabajo;*trabajo++) {
      if(c==*trabajo)
      	return(FALSO);
   }
   return(CIERTO);
}