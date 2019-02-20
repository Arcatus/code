#include <cstdio>

int arr[] = { 
	1,
	121,
	12321,
	1234321,
	123454321
};


bool escalera(int n)
{
	for (int i = 0; i < 5; ++i)
	{
		if (arr[i] == n)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int n, a, b;

	scanf("%d %d %d",&n,&a,&b);

	int segundoI = 0;

	if( escalera(n) )
	{
		printf("es escalera inicialmente\n");
	}	
	else
	{
		segundoI = n - a;
		segundoI = segundoI / (b+1);

		if ( escalera(segundoI) )
		{
			printf("es escalera despues del primer intento\n");	
		}
		else
		{
			segundoI -= (a + b);

			segundoI += 1;

			if ( escalera(segundoI) )
			{
				printf("es escalera despues del segundo intento\n");	
			}
			else
			{	
				printf("nos rendimos\n");
			}
		}
	}

	return 0;
}