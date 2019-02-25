//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int L, A;

	scanf("%d %d",&L,&A);

	int arr[L*A]{};

	int n;

	scanf("%d",&n); int x, y;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d",&x,&y);
		arr[ ( (y-1)*L) + (x-1) ] = -1;
	}

	int lugar_seguro = 0;

	for (int j = 0; j < A-1; ++j)
	{
		for ( int i = 0; i < L-1; ++i )
		{
			if ( 
				arr[ j*L + i ] == -1 ||
				arr[ j*L + i + 1 ]  == -1 ||
				arr[ (j+1)*L + i ]  == -1 ||
				arr[ (j+1)*L + i + 1 ] == -1 ){
			}
			else
			{
				lugar_seguro++;
			}
		}
	}
	printf("%d\n",lugar_seguro);
}