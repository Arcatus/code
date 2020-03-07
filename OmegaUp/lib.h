
 
typedef struct CabeceraCola{
    int longitudPalabra;
    char palabra [50];
    struct CabeceraCola *sig;
}tNodo;
 
typedef struct Cola{
    tNodo *pri;
    tNodo *ult;
}tCola;
 
typedef struct pila{
    char palabra[50];
    int longitudPlabra;
    struct pila *sig;
}tpila;
 
 
void inicia_cola(tCola *C){
    C->pri=NULL;
    C->ult=NULL;
}
//----FUNCION PONER EN COLA-------------------------------------
void poner_en_Cola(tCola *C, char palabra[]){
    tNodo *aux;
    aux=(tNodo*)malloc(sizeof(tNodo));
    strcpy(aux->palabra,palabra);
    aux->longitudPalabra=strlen(palabra);
    aux->sig=NULL;
    if ( C->pri == NULL ) {
        C->pri = aux;
        C->ult = aux;
    }
    else {
        C->ult->sig = aux;
        C->ult = aux;
    }
}
 
//----FUNCION SACAR DE COLA-------------------------------------
 
void sacar_De_Cola(tCola *C, int *longitudPalabra, char palabra[]){
    tNodo *aux;
    aux=C->pri;
    *longitudPalabra=aux->longitudPalabra;
    strcpy(palabra,aux->palabra);
    C->pri=aux->sig;
    if (C->pri==NULL){
        C->ult=NULL;
    }
    free(aux);
}
 
 
//----FUNCION MUESTRA COLA-------------------------------------

void mostrar_Cola(tCola *C) {
    
    int longitudPalabra; char palabra[50];

    if (C->pri != NULL){
        sacar_De_Cola(&*C,&longitudPalabra,palabra);
        mostrar_Cola(&*C);
        printf("Longitud: %d  Palabra: %s\n\n",longitudPalabra,palabra);
        poner_en_Cola(&*C,palabra);
    }
}
//----FUNCION VACIAR PILA-------------------------------------
 
int vacipila(tpila *P){
    return (P == NULL);
}
 
//----FUNCION PONER EN PILA-------------------------------------
 
void poner_en_pila(tpila **P, char palabra[50]){
    tpila *aux;
    aux=(tpila*)malloc(sizeof(tpila));
    aux->longitudPlabra = strlen(palabra);
    strcpy(aux->palabra,palabra);
    aux->sig=*P;
    *P=aux;
}
 
//----FUNCION SACAR DE PILA-------------------------------------
 
void sacar_de_pila (tpila **P,  char palabra[50]){
    tpila *aux;
    aux=*P;
    strcpy(palabra,aux->palabra);
    *P=aux->sig;
    free(aux);
}
//----FUNCION PASAR COLA A PILA-------------------------------------
 
void Pasarapila(tCola *C, tpila **P){
    
    int longitudPalabra; char palabra[50];
    if (C->pri!=NULL){
        sacar_De_Cola(&*C,&longitudPalabra,palabra);
        poner_en_pila(&*P,palabra);
        Pasarapila(C,&*P);
        poner_en_Cola(&*C,palabra);
   }
 
}
//----FUNCION MOSTRAR PILA-------------------------------------
 
void mostrar_Pila(tpila *P){
    char sacaPalabra [50];
    if ( !vacipila(P) ){
        sacar_de_pila(&P,sacaPalabra);
        mostrar_Pila(P);
        printf("%s\n",sacaPalabra);
        poner_en_pila(&P,sacaPalabra);
    }
}
//----INGRESA DATOS PARA LA LISTA CIRCULAR -------------------------------------
void cargaDatos(tCola *C){
    char palabra [15];
    printf("Palabra: ");
    //fflush(stdin);
    //fgets(palabra,15,stdin);
    scanf("%s",palabra);
    //palabra[strlen(palabra)-1] = 0;
    // cargaListaCircularOrdenada(&(*LC),palabra);
    poner_en_Cola(&*C,palabra);
}

int menu (){
    //system("pause");
    //system("cls");
    printf("\t\t<<<---DE LISTAS CIRCULARES A TODAS LAS ESTRUCTURAS--->>>>\n\n");
    printf(" 1- Carga DATOS EN LISTA CIRCULAR\n 2- Imprimir Lista Circular\n 3- Cargar Cola con LONGITUD DE PALABRAS\n 4- Mostrar  Cola\n 5- Pasar a Pila\n 6- Mostrar Pila \n 7- Pasar a Arbol\n 8- Mostrar Arbol\n 9- Pasar a Lista Simple\n10- Mostrar Lista Simple\n\n\n");
    int op;
    printf("Ingrese OPCION [  ]\b\b\b");
    scanf("%d",&op);
    return op;
}


//https://pastebin.com/9GEvF0BP