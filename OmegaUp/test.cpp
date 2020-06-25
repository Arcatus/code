#include <stdio.h>
#include <cmath>

float xUno{};
float xDos{};
float yUno{};
float yDos{};

float distance = 0.0f;

int main()
{
	int n;

	scanf("%d",&n);

	scanf("%f %f",&xUno ,&yUno);

	float ini_a = xUno;
	float ini_b = yUno;

	for (int i = 1; i < n; i++)
	{
		scanf("%f %f",&xDos ,&yDos);
		//printf("x1:%f y1:%f \n",xUno, yUno);
		//printf("x2:%f y2:%f \n",xDos, yDos);

		double r = hypot( xUno - xDos , yUno - yDos );

		printf("%.9lf\n",r);

		distance += r;

		xUno = xDos;
		yUno = yDos;
	}

	double r = hypot( xDos - ini_a , yDos - ini_b );

	distance += r;
    printf("%.9lf\n",r);
    
	printf("%.2f\n",distance);
}