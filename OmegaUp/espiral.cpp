//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int n, m;

	scanf("%d %d",&m,&n);

	int a[n*m]{};

	int state = 0, indexer = 0;

	int iteration = 0 + 1;

	const int iter_max = m*n + 1;

	int t_m = m;
	int t_n = n;

	while( iteration < iter_max)
	{
		if ( state == 0 ) //derecha
		{
			for(int i = 0; i < t_n ; ++i)
			{
				a[indexer++] = iteration++;
			}
			indexer--;
			state = 1;
			t_m--;
		}
		else if ( state == 1 )	//abajo
		{
			for (int i = 0; i < t_m; ++i)
			{
				indexer+=n;
				a[indexer] = iteration++;
			}
			indexer--;
			state = 2;
			t_n--;
		}
		else if ( state == 2 )	//izquierda
		{
			for(int i = 0; i < t_n ; ++i)
			{
				a[indexer--] = iteration++;
			}
			indexer++;
			state = 3;
			t_m--;
		}
		else if ( state == 3 )	//arriba
		{
			for (int i = 0; i < t_m; ++i)
			{
				indexer-=n;
				a[indexer] = iteration++;
			}
			indexer++;
			state = 0;
			t_n--;
		}
	}

	for (int i = 1; i <= m*n; ++i)
	{
		printf("%d\t",a[i-1]);
		if ( i%n==0 )
		{
			printf("\n");
		}
	}
}