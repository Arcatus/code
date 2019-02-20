#include "cubiculos.h"

int agrega(char* profesor, int cubiculo)
{
	int da=-1;
	long desplazamiento;
	char nombre[]="profesores";
	char* buf;
	if ((buf = (char*)calloc(TAMNOMBRE,sizeof(char)))==NULL)
	{
		fprintf(stderr,"No hay memoria para buffer\n");
		exit(-3);
	}
	strcpy(buf,profesor);
	if((da=open(nombre,O_WRONLY|O_CREAT,0644))==-1) 
	{
		printf("\a No pude abrir el archivo %s\n",nombre);
		exit(1);
    }
    desplazamiento = (cubiculo-1)*TAMNOMBRE;
    if(lseek(da,desplazamiento,0) < 0)
    {
    	printf("Error en lseek\n");
		return (-1);
    }
	write(da,buf,TAMNOMBRE);
    return(0);
}