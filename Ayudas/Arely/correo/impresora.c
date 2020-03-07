#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

struct Def_Struct
{
  int Paginas, Impresas, ID;
  char Nombre[50];
  struct Def_Sruct *Next;
};

typedef struct Def_Struct tDocumento;
typedef tDocumento *ptrDocumento;

void Menu(int *Opcion);
void Datos_Documento(tDocumento *Nuevo);
void Insertar_Documento(ptrDocumento *Inicio, tDocumento Nuevo);
void Listar_Documentos(ptrDocumento Inicio);
void Eliminar(ptrDocumento *Inicio);
void Imprimir(ptrDocumento *Inicio);
void Guardar_Archivo(ptrDocumento Inicio);
void Leer_Archivo(ptrDocumento *Inicio);
void Liberar_Todo(ptrDocumento *Inicio);
void Aniadir(ptrDocumento Inicio);

int main()
{
  int Opcion=0;
  ptrDocumento Inicio=NULL;
  tDocumento Nuevo;
  int totalID=100;
  do
    {
      system("clear");
      Menu(&Opcion);
      switch(Opcion)
        {
        case 1:
          Datos_Documento(&Nuevo);
          Nuevo.ID=totalID;
          Insertar_Documento(&Inicio, Nuevo);
          totalID++;
          break;
        case 2:
          Listar_Documentos(Inicio);
          break;
        case 3:
          Eliminar(&Inicio);
          break;
        case 4:
          Imprimir(&Inicio);
          break;
        case 5:
          Guardar_Archivo(Inicio);
          break;
        case 6:
          Leer_Archivo(&Inicio);
          break;
        case 7:
          Liberar_Todo(&Inicio);
          printf("Se ha liberado el espacio de las listas dinamicas exitosamente.\n");
          printf("Hasta pronto.\n\n");
          break;
        default:
          printf("Error: No me diste una opcion del menu.Presiona <enter> para regresar al menu: ");
          getchar();
          __fpurge(stdin);
        }
    }
  while(Opcion!=7);
}

void Menu(int *Opcion)
{
  printf("MENU de Cola de Impresiones\n\n");
  printf("1. Introducir documento a la cola de impresion\n");
  printf("2. Listar trabajos en la cola de impresion\n");
  printf("3. Eliminar trabajo de la cola de impresion\n");
  printf("4. Imprimir documento\n");
  printf("5. GUardar cola en archivo\n");
  printf("6. Leer cola de archivo\n");
  printf("7. Salir\n\n");
  printf("Ingresar opcion: ");
  scanf("%d", Opcion);
  __fpurge(stdin);
}

void Datos_Documento(tDocumento *Nuevo)
{
  printf("Dame el nombre del documento: ");
  fgets(Nuevo->Nombre, 50, stdin);
  __fpurge(stdin);
  Nuevo->Nombre[strlen(Nuevo->Nombre)-1]=0;
  printf("Dame el total de paginas que tiene: ");
  scanf("%d", &Nuevo->Paginas);
  __fpurge(stdin);
}

void Insertar_Documento(ptrDocumento *Inicio, tDocumento Nuevo)
{
  ptrDocumento temp, temp2;
  temp=(tDocumento*)malloc(sizeof(tDocumento));
  strcpy(temp->Nombre, Nuevo.Nombre);
  temp->Paginas=Nuevo.Paginas;
  temp->Impresas=0;
  temp->ID=Nuevo.ID;
  temp->Next=NULL;
  if(*Inicio==NULL)
    {
      *Inicio=temp;
    }
  else
    {
      temp2=*Inicio;
      while(temp2->Next!=NULL)
        {
          temp2=temp2->Next;
        }
      temp2->Next=temp;
    }
      printf("Tu archivo fue subido exitosamente a la cola de las impresiones.El ID generado para tu archivo es: %d.  Presiona <enter> para regresar al menu: ", temp->ID);
      getchar();
      __fpurge(stdin);
}

void Listar_Documentos(ptrDocumento Inicio)
{
  ptrDocumento temp;
  if(Inicio==NULL)
    {
      printf("No hay documentos en la cola de impresion.\n Presiona <enter> para regresar al menu: ");
      getchar();
      __fpurge(stdin);
    }
  else
    {
      temp=Inicio;
       while(temp!=NULL)
         {
           if(temp==Inicio)
             {
               printf("%d: %s, %d, imprimiendo, %d hojas impresa\n", temp->ID, temp->Nombre, temp->Paginas, temp->Impresas);
             }
           else
             {
               printf("%d: %s, %d hojas, espera\n", temp->ID, temp->Nombre, temp->Paginas);
             }
           temp=temp->Next;
         }
       printf("\nPresiona <enter> para regresar al menu: ");
       getchar();
       __fpurge(stdin);
    }
}

void Eliminar(ptrDocumento *Inicio)
{
  ptrDocumento temp, temp2, Borrame;
  int Borrar, Validar=0;;
  temp=*Inicio;
  if(*Inicio==NULL)
    {
      printf("NO hay nada por borrar. Presiona <enter> para regresar al menu: ");
      getchar();
      __fpurge(stdin);
    }
  else
    {
       printf("Dame el numero ID del documento que deseas borrar: ");
       scanf("%d", &Borrar);
       __fpurge(stdin);
       while(temp!=NULL)
         {
           if(Borrar==temp->ID)
             {
               Validar=1;
               if(temp==*Inicio)
                 {
                   printf("Se ha encontrado el siguiente archivo:\n");
                   printf("%d: %s, %d, imprimiendo, %d impresas\n", temp->ID, temp->Nombre, temp->Paginas, temp->Impresas);
                 }
               else
                 {
                   printf("Se ha encontrado el siguiente archivo:\n");
                   printf("%d: %s, %d, espera\n", temp->ID, temp->Nombre, temp->Paginas);
                 }
               printf("Presiona 1 si deseas borrar el archivo: ");
               scanf("%d", &Borrar);
               __fpurge(stdin);
               if(Borrar==1)
                 {
                   if(temp==*Inicio)
                     {                 
                       *Inicio=(*Inicio)->Next;
                       free(temp);
                     }
                   else
                     {
                       temp2=*Inicio;
                       while(temp2->Next!=temp)
                         {
                           temp2=temp2->Next;
                         }
                       Borrame=temp;
                       temp2->Next=temp->Next;
                       free(Borrame);
                     }
                   printf("Se ha borrado el archivo exitosamente. Presiona <enter> para regresar al menu: ");
                   getchar();
                   __fpurge(stdin);
                 }
             }
           temp=temp->Next;
         }
       if(temp==NULL&&Validar==0)
         {
           printf("No se encontro ningun archivo con ese numero de identifiacion ID. Presiona <enter> para regresar al menu: ");
           getchar();
           __fpurge(stdin);
             }
    }
 
}

void Imprimir(ptrDocumento *Inicio)
{
  ptrDocumento temp;
  temp=*Inicio;
  temp->Impresas=(temp->Impresas)+1;
  if(temp->Impresas==temp->Paginas)
    {
      printf("Se ha impreso por completo el documento %s.\n Presiona <enter> para regresar al menu: ", temp->Nombre);
      getchar();
      __fpurge(stdin);
      *Inicio=temp->Next;
      free(temp);
    }
}

void Guardar_Archivo(ptrDocumento Inicio)
{
  ptrDocumento temp;
  char Nombre[50], Opcion;
  FILE *Archivo;
  if(Inicio==NULL)
    {
      printf("No hay nada para guardar.\n");
    }
  else
    {
      printf("Dame el nombre del archivo en donde deseas guardar tu lista (sin extension): ");
      fgets(Nombre, 50, stdin);
      __fpurge(stdin);
      Nombre[strlen(Nombre)-1]=0;
      strcat(Nombre, ".txt");
      if((Archivo=fopen(Nombre, "rt"))!=NULL)
        {
          fclose(Archivo);
          printf("Ya existe un archivo. Deseeas (s)obreescribir: ");
          scanf("%c", &Opcion);
          __fpurge(stdin);
          toupper(Opcion);
          if(Opcion=='S')
            {
              Archivo=fopen(Nombre, "wt");
              temp=Inicio;
              while(temp!=NULL)
                {
                  fprintf(Archivo, "%s %d %d %d\n", temp->Nombre, temp->Paginas, temp->Impresas, temp->ID);
                  temp=temp->Next;
                }
              fclose(Archivo);
              printf("Tu lista fue guardada exitosamente en %s.\n", Nombre);
            }
        }
      else
        {
          Archivo=fopen(Nombre, "wt");
          temp=Inicio;
          while(temp!=NULL)
            {
              fprintf(Archivo, "%s %d %d %d\n", temp->Nombre, temp->Paginas, temp->Impresas, temp->ID);
              temp=temp->Next;
            }
          fclose(Archivo);
          printf("Tu lista fue guardada exitosamente en %s.\n", Nombre );
        }
    }
  printf("Presiona <enter> para regresar al menu: ");
  getchar();
  __fpurge(stdin);
}

void Leer_Archivo(ptrDocumento *Inicio)
{
  ptrDocumento temp, temp2, Borrame;
  char Nombre[50], Informacion[50], nom;
  FILE *Archivo;
  int i=0, pag, imp, id, Opcion;
  printf("Dame el nombre del archivo que deseas leer: ");
  fgets(Nombre, 50, stdin);
  __fpurge(stdin);
  Nombre[strlen(Nombre)-1]=0;
  strcat(Nombre, ".txt");
  if((Archivo=fopen(Nombre, "rt"))==NULL)
    {
      printf("No existe un archivo con ese nombre.\n");
    }
  else
    {
      if(*Inicio==NULL)
        {
          while(!feof(Archivo))
            {
              temp=(ptrDocumento)malloc(sizeof(ptrDocumento));
              fscanf(Archivo, "%s", temp->Nombre);
              fscanf(Archivo, "%d", &temp->Paginas);
              fscanf(Archivo, "%d", &temp->Impresas);
              fscanf(Archivo, "%d\n", &temp->ID);
              temp->Next=NULL;
              if(*Inicio==NULL)
                {
                  *Inicio=temp;
                }
              else
                {
                  temp2=*Inicio;
                  while(temp2->Next!=NULL)
                    {
                      temp2=temp2->Next;
                    }
                  temp2->Next=temp;
                }
            }
          printf("Se ha leido exitosamente la informacion del archivo.\n");
        }
      else
        {
          printf("Se van a sobreescribir los datos, deseas continuar: 1 para si:");
          scanf("%d", &Opcion);
          __fpurge(stdin);
          if(Opcion==1)
            {
              temp=*Inicio;
              while(*Inicio!=NULL)
                {
                  Borrame=*Inicio;
                  *Inicio=(*Inicio)->Next;
                  free(Borrame);
                }
              while(!feof(Archivo))
                {
                  temp=(ptrDocumento)malloc(sizeof(ptrDocumento));
                  fscanf(Archivo, "%s", temp->Nombre);
                  fscanf(Archivo, "%d", &temp->Paginas);
                  fscanf(Archivo, "%d", &temp->Impresas);
                  fscanf(Archivo, "%d\n", &temp->ID);
                  temp->Next=NULL;
                  if(*Inicio==NULL)
                    {
                      *Inicio=temp;
                    }
                  else
                    {
                      temp2=*Inicio;
                      while(temp2->Next!=NULL)
                        {
                          temp2=temp2->Next;
                        }
                      temp2->Next=temp;
                    }
                  temp=NULL;
                }
            }
          printf("Se sobreescribio la informacion a tus listas exitosamente.\n");
        }
      fclose(Archivo);
    }
  printf("Presiona <enter> para regresar al menu: ");
  getchar();
  __fpurge(stdin);
}

void Liberar_Todo(ptrDocumento *Inicio)
{
  ptrDocumento temp;
  temp=*Inicio;
  while(*Inicio!=NULL)
    {
      temp=*Inicio;
      *Inicio=(*Inicio)->Next;
      free(temp);
    }
}