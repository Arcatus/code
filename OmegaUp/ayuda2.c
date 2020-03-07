#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
 
 
int main()
{
    tCola C;
    tpila *P=NULL;
    inicia_cola(&C);
    int opcion=1;
    while(opcion!=0){
        opcion=menu();
        switch(opcion){
        case 1:
            cargaDatos(&C);
        break;
        case 2:
            mostrar_Cola(&C);
        break;
        case 5:
            Pasarapila(&C,&P);
        break;
        case 6:
            mostrar_Pila(P);
            break;
        }
    }
}

//https://pastebin.com/QUsLX8fS