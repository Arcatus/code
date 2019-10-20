#include <stdio.h>
#include <string.h>

int main(){

        struct user{
                char name[5];
                int edad;
        }typedef persona;

        persona p1;
        persona *ptr_persona;
        ptr_persona = &p1;

        persona p2;
        persona *ptr_persona2;
        ptr_persona2 = &p2;

        ptr_persona->edad = 20;
        ptr_persona2->edad = 23;        

        strcpy(ptr_persona -> name, "alex");
        strcpy(ptr_persona2 -> name, "carlos");

        //printf("%s %d\n", ptr_persona->name, ptr_persona->edad);
        //printf("%s %d\n", ptr_persona2->name, ptr_persona2->edad);

        //MATRIZ

        persona matriz[10][10];

        matriz[0][0] = p1;
        matriz[1][1] = p2;

        printf("Notacion 1 matriz\n");

        printf("en matriz 1.1 %s\n", matriz[0][0].name );
        printf("en matriz 2.1 %s\n", matriz[1][1].name );

        // es igual a

        printf("Notacion 2 matriz\n"); 

        printf("en matriz 1.2 %s\n", ((*(*(matriz+0)+0)).name) );
        printf("en matriz 2.2 %s\n", ((*(*(matriz+1)+1)).name) );        

        // ARRAY

        persona array[10];

        array[0] = p1;
        array[1] = p2;

        printf("Notacion 1 array\n");

        printf("en array 1.1 %s\n", array[0].name );
        printf("en array 2.1 %s\n", array[1].name );

        //es igual a

        printf("Notacion 2 array\n");

        printf("en array 1.2 %s\n", ((*(array+0)).name) );
        printf("en array 2.2 %s\n", ((*(array+1)).name) );        

        // este doble apuntador no tiene memoria solo apunta a un apuntador
        // para acceder a su valor hay que desreferenciar 2 veces

        // un doble apuntador es como apuntar a una matriz donde nosotros controlamos a donde apuntar
        // a que filas y columna, usando la notacion (*(*(matriz+ filas )+ columnas)), si no lo
        // especificamos significa que apartir de ahi

        persona **ptr;

        ptr = &ptr_persona;


        // todo esto es lo mismo

        /*
                ptr[0] funciona porque ptr = &ptr_persona le dice a partir de donde interpretar los bits 
                como persona, a partir de ahi todo se intentara interpretar como persona
        */

        printf("%s\n", ptr[0]->name ); //=>
        printf("%s\n", (*ptr + 0 )->name ); //=>
        printf("%s\n", (*ptr)->name ); // =>
        printf("%s\n", (*(*ptr)).name ); // lo de arriba solo es para que se vea menos complejo

        /*
                Entonces ptr[1]->name seria equivalente a apuntar a
                (*ptr + 1)->name
                que es desplazarse 9 bytes hacia adelante(el tamaño de persona)
                esto solo tiene sentido si tenemos memoria solicitada en esa ubicacion si la tiene
                entonces imprimira el name de esa ubicacion si no imprimira basura o tirara 
                un segmentation fault si tocamos memoria protegida
        */

        // imprime carlos (posiblemente) porque solicitamos memoria justo despues de declarar p1

        printf("%s\n",ptr[1]->name);
        
        // mueve el apuntador pero aqui no deberia haber algo sacara basura o dara error
        // o de pura suerte habra una cadena que interpretar, es el problema de usar apuntadores
        // el resultado puede ser incierto

        printf("%s\n",ptr[2]->name);

        return 0;
}