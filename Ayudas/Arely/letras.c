#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<stdlib.h>

void Pedir_Archivo(char *Nombre);
void Leer_Archivo(char *Nombre, int *Palabras, int *Min, int *Mayus, int *Letras, int *Espacios);
void Imprimir(int Palabras, int Min, int Mayus, int Letras, int Espacios);

int main()
{
  char Nombre[15];
  int Palabras=0, Min=0, Mayus=0, Letras=0, Espacios=0;
  Pedir_Archivo(Nombre);
  Leer_Archivo(Nombre, &Palabras, &Min, &Mayus, &Letras, &Espacios);
  Imprimir(Palabras, Min, Mayus, Letras, Espacios);
  return 0;
}

void Pedir_Archivo(char *Nombre)
{
  printf("Dame el nombre del archivo a leer(con extension .txt y no mayor a 15 letras): ");
  fgets(Nombre, 14, stdin);
  
  Nombre[strlen(Nombre)-1]='\0';
  //__fpurge(stdin);
  //strcat(Nombre,".txt");
  // puts(Nombre);
}

void Leer_Archivo(char
 *Nombre, int *Palabras, int *Min, int *Mayus, int *Letras, int *Espacios)
{
  FILE *Archivo;
  char c;
  char Arr[2000];
  int i=0,j,k=0,l=0;
  //char *token;
  Archivo=fopen(Nombre, "rt");
  if( Archivo != NULL ) {
      while(!(feof(Archivo))) {
        fscanf(Archivo, "%c", &c);
        __fpurge(stdin);
 
  if(c>='A' && c<='Z') {
     *Mayus=*Mayus+1;
   }
  if(c>='a' && c<='z') {
    *Min=*Min+1;
  }
  if(c==' ') {
     *Espacios=*Espacios+1;
  }
  Arr[i]=c;
  i++;
}
      *Letras=*Mayus+*Min;
      //puts(Arr);
      

      for(j=0;j<i;j++)
{
 
 //if(j>=1)
 
   {
 
     if(Arr[j]==' ' && Arr[j-1]!=' ' && Arr[j+1]!=' ')
{
 
 k++;
}
 
     /*
 
     if(Arr[j]==')
{
 
 l++;
}
 
     */
 
   }
  
}
      //printf("\n%d 
 %d\n\n", k, l);
      *Palabras=k+2+l;
      

/*
      token==' ';      
      strtok(token,)
{
}
      */
    }
  else
    {
      printf("El
 archivo no se pudo abrir.\n");
      exit(0);
    }
}

void Imprimir(int Palabras, int Min, int Mayus, int Letras, int Espacios)
{
  printf("Cantidad
 de palabras: %d\n", Palabras);
  printf("Cantidad
 de minusculas: %d\n", Min);
  printf("Cantidad
 de mayusculas: %d\n", Mayus);
  printf("Cantidad
 de letras: %d\n", Letras);
  printf("Cantidad
 de espacios: %d\n", Espacios);
}