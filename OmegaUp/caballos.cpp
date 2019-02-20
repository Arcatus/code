#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using std::cin;

int main()
{
	uint16_t t;

	uint16_t v1, v2;
	uint16_t total1 = 0; 
	uint16_t total2 = 0;

	cin >> t;

	size_t time = 0;

	uint8_t state = 0;

	int max = 0;

	for (uint16_t i = 0; i < t; ++i)
	{
		time++;

		cin >> v1 >> v2;

		total1 += v1;

		total2 += v2;

		if ( state == 1)
		{
			if( total2 > total1)
			{
				printf("Al minuto %zu el caballo 2 toma la delantera\n",time);
				state = 2;
			}
			else if ( total1 == total2 )
			{	
				printf("Al minuto %zu los caballos van empatados\n",time);
				state = 0;
			}
		}
		else if ( state == 2)
		{
			if ( total1 > total2 )
			{	
				printf("Al minuto %zu el caballo 1 toma la delantera\n",time);
				state = 1;
			}
			else if ( total1 == total2 )
			{	
				printf("Al minuto %zu los caballos van empatados\n",time);
				state = 0;
			}
		}
		else if ( state == 0)
		{
			if ( total1 > total2 )
			{	
				printf("Al minuto %zu el caballo 1 toma la delantera\n",time);
				state = 1;
			}
			else if( total2 > total1)
			{
				printf("Al minuto %zu el caballo 2 toma la delantera\n",time);
				state = 2;
			}
		}	

		if ( max < abs(total1 - total2) )
		{
			max = abs(total1 - total2);
		}
	}

	if (state == 1)
	{
		printf("Termina la carrera y gana el caballo 1\n");	
	}
	else if ( state == 2 )
	{
		printf("Termina la carrera y gana el caballo 2\n");
	}
	else
	{
		printf("Termina la carrera y empatan los caballos\n");
	}

	printf("La distancia maxima entre los caballos fue de %d\n",max);
	
}