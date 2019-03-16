//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int intervalos;
		
	scanf("%d",&intervalos);

	int arr[intervalos][2];

	for(int i = 0; i < intervalos; ++i)
	{	
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	}
	int n;
	scanf("%d",&n);
	int brr[n];
	for(int i = 0; i < n; ++i)
	{
		scanf("%d",&brr[i]);
	}
	
	for(int i = 0; i < intervalos; ++i)
	{
		int total = 0;
		
		if ( ( arr[i][1] - arr[i][0] ) % 2 == 0)
		{
			for (int j = arr[i][0], k = 0; k <  arr[i][1] - arr[i][0] ; k+=2, j+=2)
			{	
				total += brr[j] + brr[j+1];
			}
		}
		else
		{
			total += brr[ arr[i][0] ];

			for (int j = arr[i][0] + 1, k = 1; k <  arr[i][1] - arr[i][0] ; k+=2, j+=2)
			{	
				total += brr[j] + brr[j+1];
			}
		}

		printf("%d\n",total);
	}
}