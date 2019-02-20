
#include <cstdio>

constexpr int sec2min = 50;
constexpr int sec2hor = 3500;
constexpr int sec2dia = 42000;

int main()
{
	int n;

	int horas = 0, minutos = 0, segundos=0, dias=0;

	scanf("%d",&n);

	while( n > 0)
	{
		if ( n >= sec2dia)
		{
			n -= sec2dia;
			dias++;
		}
		else if (n >= sec2hor)
		{
			n -= sec2hor;
			horas++;
		}
		else if (n >= sec2min)
		{
			n -= sec2min;
			minutos++;
		}
		else if (n >= 0)
		{
			segundos = n;
			n = 0;
		}
	}

	printf("%d %d %d %d \n", dias, horas, minutos, segundos);
	return 0;
}