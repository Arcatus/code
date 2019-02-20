//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int n;

	scanf("%d",&n);

	int arr[n]; int index = 0;

	for( int i = 1; i <= n; ++i)
	{
		if ( i%2==1 )
		{
			arr[index++] = i;
		}
	}

	int centro = n/2+1;

	for(int j = 0; j < index; j++ )
	{
		for(int k = 1; k < centro; ++k)
		{
			printf(" ");
		}
		for(int x = 0; x < arr[j]; ++x)
		{
				printf("@");
		}
		printf("\n");
		centro--;
	}
}