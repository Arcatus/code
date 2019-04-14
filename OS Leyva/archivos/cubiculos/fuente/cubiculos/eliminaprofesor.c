#include "cubiculos.h"

int elimina(int cubiculo)
{
	int da=-1;
	long desplazamiento;
	char nombre[]="profesores";
	char msj[]="Cubiculo Libre";
	char* buf;
	if ((buf = (char*)calloc(TAMNOMBRE,sizeof(char)))==NULL)
	{
		fprintf(stderr,"No hay memoria para buffer\n");
		exit(-3);
	}
	if((da=open(nombre,O_WRONLY))==-1) 
	{
		printf("\a No pude abrir el archivo %s\n",nombre);
		return 0;
    }
    strcpy(buf,msj);
    desplazamiento = (cubiculo-1)*TAMNOMBRE;
    if(lseek(da,desplazamiento,0) < 0)
		return (-1);
	write(da,buf,TAMNOMBRE);
    return(0);
}