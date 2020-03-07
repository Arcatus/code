#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<ctype.h>

int cuentapalabras();
int cuentaminusculas();
int cuentamayusculas();
int cuentaletras();
int cuentaespacios();

int main(void)
{
  char palabra[20];
  printf("Ingresa el nombre de un archivo: ");
__fpurge(stdin);
fgets(palabra, 20, stdin);
FILE *archivo = fopen(palabra, "rt");
if(archivo!=NULL)
  {
fclose(archivo);
printf("numero de palabras es: \n ");
int numeropalabras = cuentapalabras();
printf("%d\n", numeropalabras);
printf("numero de minusculas es: \n ");
int numerominusculas = cuentaminusculas();
printf("%d\n", numerominusculas);
printf("numero de mayusculas es: \n ");
int numeromayusculas = cuentamayusculas();
printf("%d\n", numeromayusculas);
printf("numero de letras es: \n ");
int numeroletras = cuentaletras();
printf("%d\n", numeroletras);
printf("numero de espacios es: \n ");
int numeroespacios = cuentaespacios();
printf("%d\n", numeroespacios);
}
}


int cuentapalabras()
{
char palabra[20];
__fpurge(stdin);
fgets(palabra, 20, stdin);
FILE *archivo = fopen(palabra,"rt");
char arreglo[20];
int numeropalabras =0;
while ((fscanf(archivo,"%s", arreglo))!=EOF)
  {
numeropalabras +=1;
}
fclose(archivo);
return numeropalabras;
}

int cuentaminusculas()
{
char palabra[20];
__fpurge(stdin);
fgets(palabra, 20, stdin);
FILE *archivo = fopen(palabra,"rt");
char arreglo[20];
int numerominusculas =0;
while ((fscanf(archivo,"%s", arreglo))!=EOF)
  {
int i;
for(i=0; i<strlen(arreglo); i++)
{
if(islower(arreglo[i])!=0)
  {
numerominusculas++;
}
}
numerominusculas +=1;
}
fclose(archivo);
return numerominusculas;
}

int cuentamayusculas()
  {
char palabra[20];
__fpurge(stdin);
fgets(palabra, 20, stdin);
FILE *archivo = fopen(palabra,"rt");
char arreglo[20];
int numeromayusculas =0;
while ((fscanf(archivo,"%s", arreglo))!=EOF)
  {
int i;
for(i=0; i<strlen(arreglo); i++)
{
if(isupper(arreglo[i])!=0)
  {
numeromayusculas++;
}
}
numeromayusculas +=1;
}
fclose(archivo);
return numeromayusculas;
}

int cuentaletras()
{
int numeroletras = 0;
numeroletras = cuentaminusculas()+ cuentamayusculas();
return numeroletras;
}

int cuentaespacios()
 {
char palabra[20];
__fpurge(stdin);
fgets(palabra, 20, stdin);
FILE *archivo = fopen(palabra,"rt");
char c;
int numeroespacios =0;
while ( ( c = fgetc (archivo)) != EOF )
  {
if(c == ' ' )
  {
numeroespacios ++;
}
}
fclose(archivo);
return numeroespacios;
}