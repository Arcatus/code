#include "cubiculos.h"

int main(void)
{
	int opcion, n;
	char nombre[TAMNOMBRE];
	char* ocupante;
	do {
		printf("Seleccione una opción:\n");
		printf("1-Agregar profesor:\n");
		printf("2-Consultar número de cubiculo:\n");
		printf("3-Eliminar registro de cubiculo:\n");
		printf("4-Salir:\n");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: system("clear"); 
					printf("Introduce el número de cubiculo y el nombre del profesor.\n");
					scanf("%d",&n);fgets(nombre,TAMNOMBRE,stdin);agrega(nombre,n);break;
			case 2: system("clear"); 
					printf("Introduce el número de cubiculo.\n");
					scanf("%d",&n);
					if((ocupante=dime(n))!=NULL)
						printf("Cubículo %d:%s\n",n,ocupante);
					else printf("Error cubiculo nunca ocupado.");break;
			case 3: system("clear"); 
					printf("Introduce el número de cubiculo.\n");
					scanf("%d",&n);elimina(n);break;
			default: system("clear"); 
					printf("Hasta la próxima..\n");
			break;
		}
	} while(opcion!=4);
	return(0);
}