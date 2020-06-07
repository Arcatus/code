#include <bits/stdc++.h>
//#include <Windows.h>

using namespace std;

struct Estudiante
{

    char nombre[30];
    char cedula[15];
    char fac[20];
    char carrera[20];
    char fechadeNac[10];
    char sexo[15];
    char estadocivil[30];
    char telefono[20];
    char direccion[50];
    char cedulaux[15];

} estudiantes[10];

void pedirdatos()
{

    ofstream Datos;
    string res;

    do
    {

        //system("cls");
        Datos.open("Datos.txt", ios::app);        
        cout << "Nombre:";
        cin.getline(estudiantes->nombre, 30);
        cout << "Cedula:";
        cin.getline(estudiantes->cedula, 15);
        cout << "Facultad:";
        cin.getline(estudiantes->fac, 20);
        cout << "Carrera:";
        cin.getline(estudiantes->carrera, 20);
        cout << "Fecha de nacimiento";
        cin.getline(estudiantes->fechadeNac, 10);
        cout << "Sexo:";
        cin.getline(estudiantes->sexo, 15);
        cout << "Estado civil:";
        cin.getline(estudiantes->estadocivil, 30);
        cout << "Telefono:";
        cin.getline(estudiantes->telefono, 20);
        cout << "Direccion:";
        cin.getline(estudiantes->direccion, 15);

        Datos << estudiantes->nombre << endl;
        Datos << estudiantes->cedula << endl;
        Datos << estudiantes->fac << endl;
        Datos << estudiantes->carrera << endl;
        Datos << estudiantes->fechadeNac << endl;
        Datos << estudiantes->sexo << endl;
        Datos << estudiantes->estadocivil << endl;
        Datos << estudiantes->telefono << endl;
        Datos << estudiantes->direccion << endl;
        Datos << "-------------------------" << endl;

        Datos.close();

        cout << "Desea registrar otro estudiante?(s/n):";
        cin >> res;

        cout << "Estudiante registrado." << endl;
    } while (res == "si" || res == "Si");
}

void actualizar(ifstream &Lec)
{

    //system("cls");
    Lec.open("Datos.txt", ios::in);
    bool encontrado = false;
    char nombre[30];
    char cedula[15];
    char fac[20];
    char carrera[20];
    char fechadeNac[10];
    char sexo[15];
    char estadocivil[30];
    char telefono[20];
    char direccion[50];
    char cedulaux[15];

    cout << "Digite la cedula:";
    cin >> cedulaux;
    Lec >> nombre;
    while (!Lec.eof() && !encontrado)
    {

        Lec >> cedula;
        Lec >> fac;
        Lec >> carrera;
        Lec >> fechadeNac;
        Lec >> sexo;
        Lec >> estadocivil;
        Lec >> telefono;
        Lec >> direccion;

        if ( strcmp(cedulaux,cedula) == 0 )
        {

            cout << "1)Nombre: " << nombre << endl;
            cout << "2)Cedula: " << cedula << endl;
            cout << "3)Facultad: " << fac << endl;
            cout << "4)Carera: " << carrera << endl;
            cout << "5)Fecha de nacimiento: " << fechadeNac << endl;
            cout << "6)Sexo: " << sexo << endl;
            cout << "7)Estado civil: " << estadocivil << endl;
            cout << "8)Telefono: " << telefono << endl;
            cout << "9)Direccion: " << direccion << endl;

            encontrado = true;
        }
        Lec >> nombre;
    }

    Lec.close();

    if (!encontrado)
        cout << "Registro no encontrado" << endl;
    //system("pause>NULL");
}

void menu_estudiante()
{
    bool repite = true;

    ofstream Datos;
    ifstream Lec;

    int opcion;

    do
    {
        //system("cls");
        cout << "1) Registrar" << endl;
        cout << "2) Actualizar" << endl;
        cout << "3) Regresar " << endl;

        cout << "Ingrese opcion:";
        cin >> opcion;
        getchar();
        switch (opcion)
        {
        case 1:
            cout << "REGISTRO DE ESTUDIANTE" << endl;
            pedirdatos();
            break;
        case 2:

            actualizar(Lec);
            break;
        case 3:
            repite = false;
            break;
        }
    } while (opcion != 3);
}

void menu_pedidos()
{
}

void menu_principal()
{
    int opcion;
    do
    {
        //system("cls");
        cout << "(:MENU PRINCIPAL:)" << endl;
        cout << "1) Estudiantes |" << endl;
        cout << "2) Pedidos |" << endl;
        cout << "3) Cerrar |" << endl;

        cout << "Ingrese opcion:";
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            menu_estudiante();
            break;
        case 2:
            menu_pedidos();
            break;
        case 3:
            cout << "Que tenga un excelente dia" << endl;
            exit(1);
            break;
        }

        //system("pause>NULL");
    } while (opcion != 3);
}

int main()
{

    menu_principal();
}