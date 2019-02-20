#include <cstdio>

int main()
{
	float a, b, c;

	scanf("%f%f%f",&a,&b,&c);

	if ( b == 0.0f )
	{
		printf("indefinido\n");
	}	
	else
	{
		if ( c == 0.0f)
		{
			printf("%f \n",a/b);	
		}
		else
		{
			printf("%f %f\n",a/b + c, a/b - c);
		}
	}

	return 0;
}