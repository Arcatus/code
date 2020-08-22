#include <iostream>
#include <stdio_ext.h>

using namespace std;

#define filas 24
#define columnas 10

struct sala
{
    int asientos[filas][columnas];
};

struct pelicula
{
    string nombre;
    float precio;
    string hora;
    float ganancia = 0.0f;
    int boletos_vendidos = 0;
};

void Menu();
void agregarPelicula(struct pelicula peliculas[], int posicion, int& peliculasActivas);
void cartelera(struct pelicula peliculas[], struct sala salas[], int posicion, int peliculasActivas);
void comprarBoletos(struct sala salas[], struct pelicula peliculas[], int posicion);
void imprimirSala(struct sala salas[], int posicion);
void iniciarSalas(struct sala salas[]);
void estadisticas (struct pelicula peliculas [],struct sala salas [],int posicion, int peliculasActivas);

int main()
{
    struct sala salas[10];
    struct pelicula peliculas[10];
    int opcion;
    int posicion = 0;
    int posicionAux;
    int peliculasActivas = 0;

    iniciarSalas(salas);
    do
    {
        Menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1: {
            cartelera(peliculas, salas, posicion, peliculasActivas);
        }
        break;
        case 2: {
            agregarPelicula(peliculas, posicion, peliculasActivas);
            posicion++;
        }
        break;
        case 3: {
            estadisticas(peliculas,salas,posicion, peliculasActivas);
        } 
        break;
        case 0: {
            cout << "Gracias por comprar los boletos disfrute la funcion" << endl;
        }
        break;
        default:
            cout << "Opcion ingresada invalida." << endl;
            break;
        }
    } while (opcion != 0);
    return 0;
}

void Menu()
{
    cout << "\nElige la opcion que desea, 0 para salir\n" << endl;
    cout << "1. Comprar boletos" << endl;
    cout << "2. Agregar pelicula" << endl;
    cout << "3. Estadisticas " << endl;
    cout << "0. Salir" << endl;
}

void cartelera(struct pelicula peliculas[], struct sala salas[], int posicion, int peliculasActivas)
{
    if(peliculasActivas == 0) {
        cout << "LA CARTELERA ESTA VACIA\n" << endl;
        return;
    }
    int opcion;
    cout << "CARTELERA" << endl;
    for (int i = 0; i < posicion; i++)
    {
        cout << i+1 << ".) Titulo: " << peliculas[i].nombre << endl;
    }

    cout << "Ingrese el numero de la pelicula que desa ver: " << endl;
    cin >> opcion;

    comprarBoletos(salas, peliculas, opcion);
}

void iniciarSalas(struct sala salas[])
{

    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i< filas; i++)
        {
            for (int j = 0; j< columnas; j++)
            {
                salas[k].asientos[i][j] = 0;
            }
        }
    }
}

void imprimirSala(struct sala salas[], int posicion)
{
    system("cls");
    cout<<"\t1 2 3 4 5 6 7 8 9 10" << endl;
    for (int i = 0; i< filas; i++)
    {
        cout << "\t";
        for (int j = 0; j < columnas; j++)
        {
            if (salas[posicion].asientos[i][j]== 0)
            {
                cout << "O ";
            }
            else
            {
                cout << "x ";
            }
        }
        cout << endl;
    }
}

void comprarBoletos(struct sala salas[], struct pelicula peliculas[10], int posicion)
{
    float precioBoleto = peliculas[posicion-1].precio;
    int numeroBoletos;
    int fila;
    int columna;
    float precio;
    char opcion;
    bool VIP = false;

    cout << "Titulo: " << peliculas[posicion-1].nombre << endl;
    cout << "Precio por boleto: " << peliculas[posicion-1].precio << endl;
    cout << "Horario: " << peliculas[posicion-1].hora << endl;

    cout << "Cuantos boletos desea comprar: ";
    cin >> numeroBoletos;

    cout << "Cuenta con una membresia VIP (S/N): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S')
    {
        cout<<"MIEMBRO VIP "<<endl;
        VIP = true;
    }

    cout << "Estado actual de los asientos de la sala" << endl;
    imprimirSala(salas, posicion-1);

    for (int i = 0; i < numeroBoletos; i++)
    {
        do
        {
            cout << "Ingrese la fila: 1-24";
            cin >> fila;
        } while (fila < 1 || fila > 24);

        cout << "Ingrese la columna: 1-10";
        cin >> columna;
        while (columna < 1 || columna > 10)
        {
            cout << "Dato mal ingresado reingrese la columna: ";
            cin >> columna;
        }
        if (salas[posicion-1].asientos[fila-1][columna-1] == 1)
        {
            cout << "Asiento ocupado porfavor seleccione uno nuevo."<< endl;
            i--;
        }
        else
        {
            cout << "Asiento asignado correctamente." << endl;
            salas[posicion-1].asientos[fila-1][columna-1] = 1;
        }
    }
    if (VIP)
    {
        cout<<"MIEMBRO VIP"<<endl;
        precio = (float) numeroBoletos*precioBoleto;
        precio *= 0.90f;
    }
    else
    {
        precio = (float) numeroBoletos*precioBoleto;
    }

    cout << "------------Factura----------" << endl;
    cout << "PELICULA: " << peliculas[posicion-1].nombre << endl;
    cout << "Horario: " << peliculas[posicion-1].hora << endl;
    cout << "Precio por boleto: " << peliculas[posicion-1].precio << endl;
    cout << "Usted Compro " << numeroBoletos << " boletos" << endl;
    cout << "Total a pagar: " << precio << " lempiras "<< endl;

    peliculas[posicion - 1].ganancia += precio;
    peliculas[posicion - 1].boletos_vendidos += numeroBoletos;
}

void agregarPelicula(struct pelicula peliculas[10], int posicion, int& peliculasActivas)
{   
    cout << "Ingrese el nombre de la pelicula: ";
    __fpurge(stdin);
    getline(cin, peliculas[posicion].nombre); // para poder leer el nombre de la pelicula con espacios
    cout << "Ingrese el precio de la pelicula: ";
    cin >> peliculas[posicion].precio;
    cout << "Ingrese el horario de la pelicula: ";
    cin >> peliculas[posicion].hora;
    peliculasActivas++;
}
void estadisticas (struct pelicula peliculas [10],struct sala salas [10],int posicion, int peliculasActivas) {
    for(int i = 0; i < peliculasActivas; ++i) {
        cout << i + 1 << ") " << peliculas[i].nombre << " " << " ha vendido " << 
            peliculas[i].boletos_vendidos << " boletos y recaudado " << peliculas[i].ganancia << '\n';
    }
    cout << "Desea visualizar los asientos disponibles S/N\n";
    __fpurge(stdin);
    char opc;
    cin >> opc;
    if(opc =='S' || opc == 's') {
        int salaopc;
        cout << "Ingrese el numero de sala 1-10\n";
        __fpurge(stdin);
        cin >> salaopc;
        for(int i = 0; i < 24; ++i) {
            for(int j = 0; j < 10; ++j) {
                cout << salas[salaopc - 1].asientos[i][j];
            }
            cout << '\n';
        }
    }
    cout << '\n';
}