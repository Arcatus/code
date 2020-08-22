#include <stdio.h>
int main()
{
    int acc, add, capcovid, clientes, max, quit;
    max = 34;
    capcovid = max / 2;
    clientes = 0;
    acc = 0;
    add = 0;
    quit = 0;
    printf("-------------------Asistente de Aforo 1.0------------------------\n");
    printf("Hola, soy un asistente que te ayudara a saber si puedes recibir o no clientes en tu tienda. Actualmente tu establecimiento cuenta con un cupo de 78 personas, pero devido a las medidas implementadas, actualmente solo se permite un aforo maximo de la mitad de la capacidad total de tu establecimiento.\n");
    printf("Para conocer esto, deberas ingresar el numero de personas que entran asi como tambien el numero de personas que salen del establecimiento\n");
    while ((acc < 3))
    {
        printf("1.- Registrar entrada de clientes\n");
        printf("2.- Registrar salida de clientes\n");
        printf("3.- Salir\n");
        scanf("%i", &acc);
        if ((acc == 1))
        {
            if ((clientes < max))
            {
                printf("¿Cuantos clientes han ingresado\n");
                scanf("%i", &add);
                if (add > 0)
                {
                    printf("\n");
                    if (clientes + add > max)
                    {
                        printf("No puedes recibir esta cantidad de clientes, recueda que solo puedes tener un maximo de %i\n", max);
                    } else {
                        clientes = clientes + add;
                    }
                }
                else
                {
                    printf("El dato ingresado es incorrecto, por favor ingresa un dato correcto\n");
                }
                printf("Actualmente hay: %i clientes\n", clientes);
            }
            else
            {
                printf("No hay mas capacidad\n");
            }
        }
        if ((acc == 2))
        {
            if (clientes > 0)
            {
                printf("¿Cuantos clientes han salido\n");
                scanf("%i", &quit);
                if (quit > 0 && quit <= clientes )
                {
                    printf("\n");
                    clientes = clientes - quit;
                }
                else
                {
                    printf("El dato ingresado es incorrecto, por favor ingresa un dato correcto\n");
                }
                printf("Actualmente hay: %i clientes\n", clientes);
                printf("Excelente aun tienes capacidad\n");
            } else {
                printf("No hay clientes\n");
            }
        }
    }
    printf("Se ha salido del programa\n");
    return 0;
}