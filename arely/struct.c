#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>


struct Def_Paciente
{
  char Nombre[50], Genero;
  int Edad;
  float Peso;
};

typedef struct Def_Paciente tPaciente;

void DespliegaPaciente(tPaciente Paciente);
void LeePaciente(tPaciente *Paciente);


int main()
{
  tPaciente UnPaciente, MisPacientes[100];
  LeePaciente(&UnPaciente);
  DespliegaPaciente(UnPaciente);
  return 0;
}

void LeePaciente(tPaciente *Paciente)
{
  printf("Dame los datos de un paciente:\n");
  printf("Nombre: ");
  fgets( (*Paciente).Nombre,50,stdin);
  /*
    (*Paciente). Es lo mismo que Paciente->
    Por ejemplo:
    (*Paciente).Nombre es lo mismo que Paciente->Nombre
    (* Paciente).Genero es lo mismo que Paciente->Genero
    &(*Paciente).Genero es lo mismo que &Paciente->Genero
  */
  Paciente->Nombre[strlen(Paciente->Nombre)-1] = 0;
  __fpurge(stdin);
  printf("Genero: ");
  scanf("%c", &Paciente->Genero);
  /*
  &Paciente ->Genero se lee como la direccion de memoria de campo Genero de la estructura que esta siendo apuntada o referenciada por el pointer Paciente
  */
  __fpurge(stdin);
  printf("Edad: ");
  scanf("%d", &Paciente->Edad);  scanf("%d", &Paciente->Edad);

  __fpurge(stdin);
  printf("Peso: ");
  scanf("%f", &Paciente->Peso);
  __fpurge(stdin);
}

void DespliegaPaciente(tPaciente Paciente)
{
  printf("Los datos de un paciente son:\n");
  printf("Nombre: %s\n",Paciente.Nombre);
  printf("Genero: %c\n",Paciente.Genero);
  printf("Edad: %d\n",Paciente.Edad);
  printf("Peso: %.2f\n",Paciente.Peso);
}