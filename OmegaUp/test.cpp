//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int hora_inicio, hora_fin;
	scanf("%d %d",&hora_inicio,&hora_fin);

	int duracion = 0;

	if ( hora_inicio == hora_fin )
	{
		printf("24\n");
	}
	else
	{
		while( hora_inicio != hora_fin )
		{
			if ( hora_inicio < 24 )
			{
				duracion++;
				hora_inicio++;
			}	
			else 
			{
				hora_inicio = 0;
			}
		}
		printf("%d\n",duracion );
	}
}