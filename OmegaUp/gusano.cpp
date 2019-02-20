#include <cstdio>

int main()
{
	int n, u, d; 

	scanf("%d %d %d",&n, &u, &d);

	int delta = u - d;

	int min = 1;
	int inc = u;

	if ( n  < u )
	{
		printf("1\n");
	}else
	{
		while( inc < n )
		{
			min+=2;
			if ( inc == n )
			{
				min++;
			}
			inc += delta;
		}
		printf("%d\n",min);
	}
	return 0;
}