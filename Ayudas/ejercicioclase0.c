#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//suficiente para lo que solicita el problema
typedef struct cuenta {
    int id;
    char nombre[50];
    char password[50];
    double saldo;
} Cuenta;

int menu();
Cuenta *abrirCuenta();
void consultaSaldo(Cuenta**, int);
void depositarCuenta(Cuenta**, int);
void retirarCuenta(Cuenta**, int);

int main(int argc, char** argv) {
    //desplegamos menu y obtenemos opcion
    //maximo 100 clientes, usando memoria local
    int opc, id_max = 0;
    Cuenta *base_datos[100];
    do{
        opc = menu();
        switch (opc) {
            case 1: { // abrir cuentas
                Cuenta *nuevoUsuario = abrirCuenta(id_max);
                if(nuevoUsuario != NULL) {
                    base_datos[id_max++] = nuevoUsuario;
                }
            } break;
            case 2: { // depositar cuenta 
                depositarCuenta(base_datos, id_max);
            } break;
            case 3: { // retirar
                retirarCuenta(base_datos, id_max);
            } break;
            case 4: { // consultar saldo
                consultaSaldo(base_datos, id_max);
            } break;
            default: {
                //
            }
        }
    } while(opc != 5);
    for(int i = 0; i < id_max; ++i) free(base_datos[i]);
    return 0;
}

Cuenta* abrirCuenta(int id) {
    printf("Saludos esta por crear una cuenta a continuacion ingresara sus datos\n");
    Cuenta *nuevoUsuario = (Cuenta*) malloc(sizeof(Cuenta));    
    printf("Ingresa tu nombre (sin espacios):\n");
    scanf("%s",nuevoUsuario->nombre);
    char verification[50];
    do {
        printf("Ingresa tu contrasenia:\n");
        scanf("%s",nuevoUsuario->password);
        printf("Ingresa nuevamente tu contrasenia:\n");
        scanf("%s",verification);
        if(strcmp(verification, nuevoUsuario->password)==0) {
            printf("Se ha guardado tu nueva contrasenia\n");
            nuevoUsuario->id=id;
            break;
        } else {
            printf("Las contrasenias no son iguales, deseas ingresar de nuevo S/N\n");
            char opc;
            getchar();
            scanf("%c",&opc);
            if(opc=='S') {
                continue;
            } else {
                printf("Cancelando abrir cuenta\n");
                free(nuevoUsuario);
                return NULL;
            }
        }
    } while(true);
    printf("¿Cuanto desea hacer de deposito inicial?\n");
    double deposito_inicial;
    scanf("%lf", &deposito_inicial);
    while(1000.0>deposito_inicial||deposito_inicial>10000.0) {
        printf("No es posible realizar depositos mayores a $10000, ni menores a $1000\n");
        printf("Por favor, ingrese otra cantidad:\n");
        scanf("%lf", &deposito_inicial);
    }
    nuevoUsuario->saldo+=deposito_inicial;
    printf("[ Felicidades %s tu nueva cuenta ha sido creada ]\n\n\n",nuevoUsuario->nombre);
    return nuevoUsuario;
}

void depositarCuenta(Cuenta **data_base, int id_max) {
    int pos;
    double saldo = -1;
    printf("Ingresa tu nombre (sin espacios):\n");
    char data[50];
    scanf("%s",data);
    printf("Ingresa tu contrasenia:\n");
    char pass[50];
    scanf("%s",pass);
    for(int i = 0; i < id_max; ++i) {
        if(strcmp(data_base[i]->nombre, data) == 0 && 
            strcmp(data_base[i]->password, pass) == 0) {
                pos = i;
                saldo = data_base[i]->saldo;
        }
    }
    if(saldo < 0.0) {
        printf("No se ha encontrado el usuario verifique sus credenciales\n\n\n");
    } else {
        printf("Su saldo actual es: %lf\n\n", data_base[pos]->saldo);
        printf("Ingresa la cantidad a depositar en pesos:\n");
        double deposito;
        scanf("%lf", &deposito);
        while(10.0>deposito||deposito>10000.0) {
            printf("No es posible realizar depositos mayores a $10000, ni menores a $10\n");
            printf("Por favor, ingrese otra cantidad:\n");
            scanf("%lf", &deposito);
        }
        if(data_base[pos]->saldo+deposito < 1000000.0) {
            data_base[pos]->saldo+=deposito;
            printf("Se ha depositado correctamente!!!\n");
        } else {
            printf("La cuenta excede el limite total, no puede seguir depostiando\n");
        }
    }
}

void retirarCuenta(Cuenta **data_base, int id_max) {
    int pos;
    double saldo = -1;
    printf("Ingresa tu nombre (sin espacios):\n");
    char data[50];
    scanf("%s",data);
    printf("Ingresa tu contrasenia:\n");
    char pass[50];
    scanf("%s",pass);
    for(int i = 0; i < id_max; ++i) {
        if(strcmp(data_base[i]->nombre, data) == 0 && 
            strcmp(data_base[i]->password, pass) == 0) {
                pos = i;
                saldo = data_base[i]->saldo;
        }
    }
    if(saldo < 0.0) {
        printf("No se ha encontrado el usuario verifique sus credenciales\n\n\n");
    } else {
        printf("Su saldo actual es: %lf\n\n", data_base[pos]->saldo);
        printf("Ingresa la cantidad a retirar en pesos:\n");
        double retiro;
        scanf("%lf", &retiro);
        while(10.0>retiro||retiro>8000.0) {
            printf("No es posible realizar retiros mayores a $8000, ni menores a $100\n");
            printf("Por favor, ingrese otra cantidad:\n");
            scanf("%lf", &retiro);
        }
        if(data_base[pos]->saldo - retiro >= 0.0) {
            if(retiro>=5000.0&&retiro<=8000.0) {
                printf("Su retiro tendra una comision del 1%");
                double comision = retiro/100.0;
                printf("Descontando comision %lf ", comision);
		retiro += comision;
            }
            data_base[pos]->saldo-=retiro;
            printf("Se ha retirado correctamente, no olvide tomar su dinero!!!\n");
        } else {
            printf("La cuenta no tiene suficientes fondos, no es posible retirar\n");
        }
    }
}

void consultaSaldo(Cuenta **data_base, int id_max) {
    int pos;
    double saldo = -1;
    printf("Ingresa tu nombre (sin espacios):\n");
    char data[50];
    scanf("%s",data);
    printf("Ingresa tu contrasenia:\n");
    char pass[50];
    scanf("%s",pass);
    for(int i = 0; i < id_max; ++i) {
        if(strcmp(data_base[i]->nombre, data) == 0 && 
            strcmp(data_base[i]->password, pass) == 0) {
                pos = i;
                saldo = data_base[i]->saldo;
        }
    }
    if(saldo < 0.0) {
        printf("No se ha encontrado el usuario verifique sus credenciales\n\n\n");
    } else {
        printf("\n\n\nSaludos %s saldo actual es: %.2lf\n\n\n", data_base[pos]->nombre ,saldo);
    }
}

int menu() {
    int opc;
    printf("===============================================\n");
    printf("Menu banco\n");
    printf("1- Deseas abrir una cuenta bancaria\n");
    printf("2- Deseas depositar a una cuenta bancaria\n");
    printf("3- Deseas retirar de una cuenta bancaria\n");
    printf("4- Deseas consultar el saldo de una cuenta bancaria\n");
    printf("5- Salir\n");
    printf("===============================================\n");
    scanf("%d",&opc);
    return opc;
}
