/*********************************************
autor: hpl 
modificaci'on: mn-7-10 (2143036080)
Descripci'on:
Con la lista de argumentos validada 
procedemos a ejecutar execvp con PATH en bin
y de argumentos un array que termina en NULL.
**********************************************/

#include "uamashell.h"

int sistema(char** lineacomandos, int donde)
{
   pid_t pid, estadosalida, retorno;
   if((pid=fork()) < 0)
      error("shellcito");
   if(!pid) {
      execvp(*lineacomandos,lineacomandos);
      error(*lineacomandos);
   }
   if(donde==SEGUNDOPLANO)
   {
   	printf("[Process id %i]",pid);
   	return(0);
   }
   while((retorno=wait(&estadosalida))!=pid && retorno !=-1) 
   	;
   return((retorno==-1)?-1:(estadosalida>>=8,estadosalida&=0xFF));
}