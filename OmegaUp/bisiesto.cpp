#include <cstdio>

void bisiesto( int a )
{
	if ( a % 4 == 0 )
	{
		if ( a % 100 == 0 )
		{
			if ( a % 400 == 0 )
			{
				printf("29 ");
			}
			else
			{
				printf("28 ");
			}
		}	
		else
		{
			printf("29 ");
		}
	}
	else
	{
		printf("28 ");
	}
}

int main()
{
	int a, b, c, d;

	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	bisiesto(a);

	bisiesto(b);

	bisiesto(c);

	bisiesto(d);

	putchar('\n');

	return 0;

}