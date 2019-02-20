#include "cubiculos.h"

char* dime(int cubiculo)
{
	int da=-1, leern;
	long desplazamiento;
	char nombre[]="profesores";
	char* buf;
	if ((buf = (char*)calloc(TAMNOMBRE,sizeof(char)))==NULL)
	{
		fprintf(stderr,"No hay memoria para buffer\n");
		exit(-3);
	}
	if(da==-1)
	{
		if((da=open(nombre,O_RDONLY))<0)
			printf("Error en open\n");		
			return NULL;
	}
	desplazamiento = (cubiculo-1)*TAMNOMBRE;

	if(lseek(da,desplazamiento,0) < 0)
	{
		printf("Error en lseek\n");
		return NULL;
	}
	leern=read(da,buf,TAMNOMBRE);
	if(leern<=0)
	{
		printf("Error en read\n");
		return NULL;
	} else {
		buf[leern-1]='\0';
		return(buf);
	}
}