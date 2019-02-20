/*********************************************
autor: hpl 
modificaci'on: mn-7-10 (2143036080)
Descripci'on:
Shell capaz de correr comandos empleando los 
binarios del sistema operativo(execvp).

**********************************************/

#include "uamashell.h"

int main(int argc, char** argv) // Se espera recibir argumentos en linea de comandos al ser llamada
{
  char* prompt; char bufferentrada[MAXBUF]; // Apuntador a prompt y buffer para almacenar los comandos
  
  if (argc > 2) { // Solo se acepta el programa y el nuevo nombre de prompt sino error

    fprintf(stderr, "Uso: %s prompt\n",argv[0]); // Como usar adecuadamente el programa entonces salir
  	exit(-1); // No termina adecuadamente 
  }
  prompt = (argc==1)?">":argv[1]; // Si no se mando nuevo nombre de prompt se deja > 
  printf("Uamashell ver 1.0\n");
  printf(R"EOF(
 █    ██  ▄▄▄       ███▄ ▄███▓ ▄▄▄      
 ██  ▓██▒▒████▄    ▓██▒▀█▀ ██▒▒████▄    
▓██  ▒██░▒██  ▀█▄  ▓██    ▓██░▒██  ▀█▄  
▓▓█  ░██░░██▄▄▄▄██ ▒██    ▒██ ░██▄▄▄▄██ 
▒▒█████▓  ▓█   ▓██▒▒██▒   ░██▒ ▓█   ▓██▒
░▒▓▒ ▒ ▒  ▒▒   ▓▒█░░ ▒░   ░  ░ ▒▒   ▓▒█░
░░▒░ ░ ░   ▒   ▒▒ ░░  ░      ░  ▒   ▒▒ ░
                            ██████  ██░ ██ ▓█████  ██▓     ██▓    
                          ▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    
                          ░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░    
                            ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    
                          ▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒
                          ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░
                          ░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░
)EOF");
  printf("Para salir presione q.\n");
  while(leerlinea(prompt,bufferentrada)!=EOF) // Sino EOF, llena buffer y genera caracter nulo
  	procesalinea(bufferentrada); //
  printf("Saliendo cerrando conexiones...\n");
  return(0); // Termina adecuadamente
}