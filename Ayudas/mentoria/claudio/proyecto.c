#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include<locale.h>
#include<string.h>
//#include<Windows.h>

char opc;
int opc2;
struct info
{
    char cod_est[9],nom_est[25],Apel_est[30];
    int sem_est,cod_carr, edad_est;
    float prom_est;
}dato1,dato2;

void bienvenida()
{
    //system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tHola, Bienvenido\n\n");
    //Sleep(4000);
}

void Salir()
{
    //system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEscogiste la opción de salir\n");
    //Sleep(3000);
    //system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tCerrando el programa...\n");
    //Sleep(4000);
}

void Error()
{
    //system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t¡¡Error!!\n");
    //Sleep(2000);
    //system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tDato ingresado no valido\n");
    //Sleep(3000);
}

void empleados()
{
    //system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t\tMENÚ EMPLEADO");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t¿Qué desea hacer?\n\n");
    printf("\n\t\t\t\t\t\ 1)Capturar datos de empleado\n\n");
    printf("\n\t\t\t\t\t\ 2)Sueldo\n\n");
    printf("\n\t\t\t\t\t\ 3)Derecho a vacaciones\n\n");
    opc=tolower(getch());
    switch(opc)
    {
        case '1':
            captura();
            break;
        case '2':
            sueldo();
            break;
        case '3':
            vacaciones();
            break;
         case '5':
            Salir();
            break;
        default: Error();
    }
}

void captura()
{
    //system("cls");
    printf("\t\tCAPTURA DE DATOS DEL EMPLEADO\n\n");
    printf("Dame el código de empleado: ");
    gets(dato1.cod_est);
    printf("Dame sus apellidos: ");
    gets(dato1.Apel_est);
    printf("Dame su nombre\(s\): ");
    gets(dato1.nom_est);
    fflush(stdin);
    printf("Dame el puesto que desempeña: ");
    scanf("%d",&dato1.sem_est);
    printf("Dame el código del puesto que desempeña: \n");
    gets(dato1.cod_carr);
    printf("Dame la edad del empleado: \n");
    gets(dato1.edad_est);

    //system("pause");




}

void mostrar()
{
    //system("cls");
    printf("\t\tMOSTRAR LOS DATOS DEL ESTUDIANTE\n\n");
    printf("\tCódigo del estudiante: %s\tCódigo de la carrera: %d\n",dato1.cod_est,dato1.cod_carr);
    printf("\tNombre del estudiante: %s %s\n",dato1.Apel_est,dato1.nom_est);
    printf("\tEdad: %d\tSemestre: %d\n",dato1.edad_est,dato1.sem_est);
    printf("\tPromedio final del semestre: %f\n",dato1.prom_est);
    printf("\nSON TODOS LOS DATOS DEL ESTUDIANTE\n");
    //system("pause");
}

void sueldo()
{
    int tarjeta;
    //system("cls");
    printf("\n\n\n\n\n\t\t\t\t\tLa próxima fecha de corte sera el 04/11/2020");
    printf("\n\n\n\n\n\n\n\t\t\t\t\tPor favor, señale cuál es su puesto de trabajo");
    printf("\n\t\t\t\ 1)Tesorero\n\n");
    printf("\n\t\t\t\ 2)Staff\n\n");
    printf("\n\t\t\t\ 3)Gerente\n\n");
    scanf("%d",&opc2);

    if(opc2==1)
    {
        //system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\tTu próximo sueldo es de $1600");
        //Sleep(3000);
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t¿Cuántas tarjetas especiales vendiste desde el último corte?: ");
        scanf("%d",&tarjeta);
        if(tarjeta>=30)
        {
            //system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tMuy bien! Agregaremos un bono a tu sueldo");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tAhora tu próximo sueldo es de $1950");
            //Sleep(3000);
        }
        else
        {
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tNo alcanzaste la meta, sigue intentando...");
            //Sleep(3000);
        }
    }
    if(opc2==2)
    {
        //system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\tTu próximo sueldo es de $1450");
        //Sleep(3000);
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t¿Cuántas tarjetas especiales vendiste desde el último corte?: ");
        scanf("%d",&tarjeta);
        if(tarjeta>30)
        {
            //system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tMuy bien! Agregaremos un bono a tu sueldo");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tAhora tu próximo sueldo es de $1700");
            //Sleep(3000);
        }
        else
        {
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tNo alcanzaste la meta, sigue intentando...");
            //Sleep(3000);
        }
    }
    if(opc2==3)
    {
        //system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\tTu próximo sueldo es de $2000");
        //Sleep(3000);
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t¿Cuántas tarjetas especiales vendiste desde el último corte?: ");
        scanf("%d",&tarjeta);
        if(tarjeta>30)
        {
            //system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tMuy bien! Agregaremos un bono a tu sueldo");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tAhora tu próximo sueldo es de $2300");
            //Sleep(3000);
        }
        else
        {
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tNo alcanzaste la meta, sigue intentando...");
            //Sleep(3000);
        }
    }



}

void vacaciones()
{

}


void clientes()
{



}


void menu()
{
    //system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\¿Qué programa quiere usar?\n\n");
    //Sleep(2000);
    printf("\n\t\t\t\t\t\ a)Para empleados\n\n");
    printf("\n\t\t\t\t\t\ b)Para clientes\n\n");
    printf("\n\t\t\t\t\t\ s)Salir del programa\n\n");
    opc=tolower(getch());
    switch(opc)
    {
        case 'a':
             'A';
            empleados();
            break;
        case 'b':
             'B';
            clientes();
            break;
        case 's':
             'S';
            Salir();
            break;
        default: Error();
    }
}


main()
{
    //system("color 02");
    setlocale(LC_ALL,"");
    bienvenida();

    do
    {
        menu();
    }
    while(opc!='s');
}