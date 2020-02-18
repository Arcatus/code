//estructuras y archivos
//pregunta cuantos pacientes ingresaras
//los ordena y los guarda en un archivo

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include <strings.h>
#include <stdlib.h>

#define TOTAL 100

struct Def_Paciente
{
  char Nombre[50], Genero;
  int Edad;
  float Peso;
};

typedef struct Def_Paciente tPaciente;

int Define_n(tPaciente **MisPacientes);//el pointer del pointer.
void LeePacientes(int n, tPaciente MisPacientes[]);
void OrdenaPacientes(int n, tPaciente MP[]);
void DespliegaPacientes(int n, tPaciente MP[]);
void EscribeArchivo(int n, tPaciente MP[]);

int main()
{
  tPaciente  *MisPacientes=NULL; //pointer del arreglo dinamico. (no tiene tamanio aun).NULL es valor de inicio para que sepas que esta vacio
  int n;
  if ( (n = Define_n(&MisPacientes)) !=0)
    {
  LeePacientes(n, MisPacientes);
  OrdenaPacientes(n, MisPacientes);
  DespliegaPacientes(n, MisPacientes);
  EscribeArchivo(n, MisPacientes);
  free((void*)MisPacientes); //liberar memoria!!!
    }
  else
    {
      printf("Error. no hay suficiente memoria para tus pacientes. Adios.\n ");
    }
  return 0;
}

int Define_n(tPaciente **MisPacientes)
{
  int n;
  printf("Dime cuantos pacientes vas a ingresar (5 a 100): ");
  scanf("%d", &n);
  __fpurge(stdin);
  if( (*MisPacientes = (tPaciente*)malloc(sizeof(tPaciente)*n)) != NULL) // sizeof devuekveo calcula  el tamano el bytes de lo que pongas en los parentesis.
    {
      return n;
    }
  else
    {
      return 0;
    }
}

void LeePacientes(int n, tPaciente MisPacientes[])
{
  int i;
  printf("Ingresa los datos de los pacientes.\n");
  for (i=0; i<n; i=i+1)
    {
      printf("Paciente %d\n", i+1);
      printf("\tNombre: ");
      fgets(MisPacientes[i].Nombre,50,stdin);
      MisPacientes[i].Nombre[strlen(MisPacientes[i].Nombre)-1] = 0;
      printf("\tGenero: ");
      scanf("%c", &MisPacientes[i].Genero);
      __fpurge(stdin);
       printf("\tEdad: ");
      scanf("%d", &MisPacientes[i].Edad);
      __fpurge(stdin);
       printf("\tPeso: ");
      scanf("%f", &MisPacientes[i].Peso);
      __fpurge(stdin);
    }
}

void OrdenaPacientes(int n, tPaciente MP[])
{
  int i, j;
  tPaciente Hoja;
  for(i=0; i<=n-2; i=i+1)
    {
      for(j=i+1; j<=n-1; j=j+1)
{
 if (strcasecmp(MP[i].Nombre,MP[j].Nombre)>0)
   {
     Hoja = MP[i];
     MP[i] = MP[j];
     MP[j] = Hoja;
   }
}
    }
}

void DespliegaPacientes(int n, tPaciente MP[])
{
  int i;
  printf("Esta es la lista de tus pacientes.\n");
  for(i=0; i<n; i=i+1)
    {
      printf("%10s, %c, %2d, %6.2f\n", MP[i].Nombre,MP[i].Genero, MP[i].Edad, MP[i].Peso );
    }
}

void EscribeArchivo(int n, tPaciente MP[])
{
  FILE *Archivo;
  char Nombre[50];
  int i;
  printf("Dame el nombre del archivo en el que guardaras a tus pacientes: ");
  fgets(Nombre,50,stdin);
  Nombre[strlen(Nombre)-1] = 0;
  Archivo = fopen(Nombre, "wt");
  fprintf(Archivo, "%d\n", n);
  for(i=0; i<n; i=i+1)
    {
      fprintf(Archivo, "%s\n", MP[i].Nombre);
      fprintf(Archivo, "%c\n", MP[i].Genero);
      fprintf(Archivo, "%d\n", MP[i].Edad);
      fprintf(Archivo, "%f\n", MP[i].Peso);
    }
  fclose(Archivo);
}