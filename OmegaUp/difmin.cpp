//#include <iostream>
#include <cstdio>
#include <climits>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int n, t;

	scanf("%d",&n); int arr[n];

	for( int i = 0; i < n; ++i )
	{
		scanf("%d",&arr[i]);
	}				
	int min = INT_MAX;

	for(int i = 0; i < n; ++i)
	{
		for (int j = 0 ; j < n; j++ )
		{
			if (i == j)continue;

			if (arr[i] >= arr[j])
			{
				t = arr[i] - arr[j];
				if (t < min)
				{
					min = t;
				}
			}
		}
	}
	printf("%d\n",min);
}