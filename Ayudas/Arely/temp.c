#include <stdio.h>
#include <stdio_ext.h>

void    LeerTemps(int temps[]);
void  ListarTemps(int temps[]);
void GuardarTemps(int temps[]);
void  CargarTemps(int temps[]);
void    PintaMenu(void);

// Este valor indica la cantidad de temperaturas que vayamos a leer
int n_files = 5;

/*
  Programa que lee n temperaturas, las guarda en un array, este se puede respaldar en archivos
  y cargar desde ellos
*/

int main(void)
{
  int Lista[n_files], opcion;
  do
    {
      PintaMenu();
      scanf("%d", &opcion);
      switch(opcion)
      {
      case 1: LeerTemps(Lista);
       break;
      case 2: ListarTemps(Lista);
       break;
      case 3: GuardarTemps(Lista);
       break;
      case 4: CargarTemps(Lista);
       break;
      case 5: printf("Gracias por usarme. Adios.\n");
       break;
      default: printf("Opcion invalida\n");
       break;
       
      }
    } while(opcion !=5);
}



void LeerTemps(int temps[])
{

  int i;
  for(i=0; i<n_files; i++)
    {
      printf("Introduzca temp %d: ", i+1);
      scanf("%d", &temps[i]);
    }
}

void ListarTemps(int temps[])
{
  int i;
  printf("Las temperaturas introducidas son: \n");
  for(i=0; i<n_files; i++)
    printf("%d\n", temps[i]);
}

void GuardarTemps(int temps[])
{
  int i;
  char nombrearchivo[30];
  
  FILE *archivo;

  printf("Introduzca el nombre del archivo: ");

  __fpurge(stdin);
  
  fgets(nombrearchivo,15,stdin);
  
  archivo = fopen(nombrearchivo, "r+");

  if( archivo != NULL ) {
      printf("El nombre del archivo ya existe");
      fclose(archivo);
  } else {
      archivo = fopen(nombrearchivo, "w+");
      for(i=0; i<n_files;i++) {
        fprintf(archivo, "%d\n", temps[i]);
      }
      fclose(archivo);
    }
}

void CargarTemps(int temps[])
{
  int i;
  char nombrearchivo[30];
  FILE *archivo;
  printf("Introduza el nombre del archivo a leer: ");

  __fpurge(stdin);

  fgets(nombrearchivo,30,stdin);

  archivo = fopen(nombrearchivo, "r+");

  if( archivo == NULL ) {
    printf("\nEl archivo especificado no existe\n");
  } else {
      for(i=0;i<n_files;i++){
        fscanf(archivo,"%d\n", &temps[i]);
      }
      printf("Temperauras cargadas con exito...\n");
      fclose(archivo);
    }
}

void PintaMenu(void)
{
  printf("\n 1. Leer temperaturas\n");
  printf(" 2. Listar Temperauras\n");
  printf(" 3. Guardar temperaturas en un archivo\n");
  printf(" 4. Cargar temperaturas de archivo\n");
  printf(" 5. Salir\n");
}