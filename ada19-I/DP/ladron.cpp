#include <cstdio>

int main()
{
	int n, c;
	scanf("%d %d",&n,&c);
	
	int arr[n];
	int memoria[n+2][c+1];

	for (int i=0; i<n; ++i) 
	{
		scanf("%d",&arr[i]);
	}

	for (int i=0;i<=c;++i)
	{
		memoria[n+1][i] = memoria[n][i] = 0;
	}

	for (int i=n-1; i>=0; --i)
	{
		for (int j=0; j<=c; ++j)
		{
			int res = memoria[i + 1][j];
			if (arr[i] <= j) {
				if ( res < memoria[i + 2][j - arr[i]] + arr[i] )
				{
					res = memoria[i + 2][j - arr[i]] + arr[i];
				}
			}
			memoria[i][j] = res;
		}
	}

	printf("%d\n",memoria[0][c]);

	int i=0, j=c;

	while( memoria[i][j] ) {
		if ( memoria[i+2][j-arr[i]] + arr[i] == memoria[i][j] )
		{
			printf("%d ",i);
			j -= arr[i];
			i +=2;
			continue;
		}
		i+=1;
	}
	return 0;
}