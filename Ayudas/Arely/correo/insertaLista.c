//ya por ultimo este programa inserta números en orden en una lista (inicio, final o en medio )

#include<stdio.h>
#include<stdlib.h>

typedef struct Def_Dato
{
 int Dato;
 struct Def_Dato *Next;
 struct Def_Dato *Prev;
}tDato;

typedef tDato *ptrDato;

void Inserta(tDato **Inicio);
void Imprimir(tDato *Inicio);
void BorraLista(tDato **Inicio);

int main()
{
int Opcion, V1, i=0;
 tDato *Inicio=NULL;
 do
   {
 printf("MENU\n1.Insertar Numero.\n2.Imprimir lista.\n3.Salir\n");
 scanf("%d", &Opcion);
 switch(Opcion)
   {
   case 1:
     Inserta(&Inicio); 
     break;
   case 2:
     printf("Aqui esta tu lista:\n");
     Imprimir(Inicio);
     break;
   case 3:
     BorraLista(&Inicio);
     exit(100);
     break;
   }
   }while(Opcion!=3);
}



void Inserta(tDato **Inicio)
{
 tDato *temp, *pos;
 temp=(tDato*)malloc(sizeof(tDato));
 printf("Inserta un numero: ");
 scanf("%d",&(temp->Dato));
 if (*Inicio !=NULL)
   {
     pos=*Inicio;
     while((pos!=NULL)&&(temp->Dato >  pos->Dato))
        pos=pos->Next;
     if(pos != (*Inicio))
        {
          if(pos!=NULL)
            {
              temp->Next=pos;
              temp->Prev=pos->Prev;
              pos->Prev=temp;
              pos=temp->Prev;
              pos=temp;
            }
          else
            {
              pos=*Inicio;
              while (pos->Next!=NULL)
                pos =pos->Next;
              pos->Next=temp;
              temp->Prev=pos ;
              temp->Next=NULL;
            }
        }
     else
        {
          temp->Next=*Inicio;
          temp->Prev=NULL;
          (*Inicio)->Prev=temp;
          *Inicio=temp;
        }
   }
 else
   {
     temp->Next=NULL;
     temp->Prev=NULL;
     *Inicio=temp;
   }
}


void Imprimir(tDato *Inicio)
{
 tDato *temp=Inicio;
 while(temp!=NULL)
   {
     printf("%d\n", temp->Dato);
     temp=temp->Next;
   }
}


void BorraLista(tDato **Inicio)
{
 tDato *temp;
 while(*Inicio!=NULL)
   {
     temp=*Inicio;
     *Inicio=(*Inicio)->Next;
     free(temp);     
   }
}