#include "cluedo.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>

void ResolverCaso() {

	srand(time(NULL));

	int c=(rand()%6)+1;
	int u=(rand()%10)+1;
	int a=(rand()%6)+1;

	int respuesta=-1;

	int sospechosos[6];
	for(int i=0;i<6;++i) sospechosos[i] = 0;

	int ubicaciones[10];
	for(int i=0;i<10;++i) ubicaciones[i] = 0;

	int armas[6];
	for(int i=0;i<6;++i) armas[i] = 0;

	while(true)
	{
		respuesta = Teoria(c,u,a);

		if (respuesta==0) return;
		else
		{
			if (respuesta==1)
			{
				sospechosos[c-1] = -1;
			} 
			else if (respuesta==2) 
			{
				ubicaciones[u-1] = -1;
			} 
			else if(respuesta==3) 
			{
				armas[a-1] = -1;
			}
		}
		do{
			c=(rand()%6) + 1;
		}while(sospechosos[c-1]!=0);
		do{
			u=(rand()%10) + 1;
		}while(ubicaciones[u-1]!=0);
		do{
			a=(rand()%6) + 1;
		}while(armas[a-1]!=0);
	}
}