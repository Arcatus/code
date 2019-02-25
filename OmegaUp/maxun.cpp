//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int n;

	scanf("%d",&n);

	int arr[n];

	scanf("%d",&arr[0]);

	int max = arr[0];

	for (int i = 1; i < n; ++i)
	{
		scanf("%d",&arr[i]);

		if ( arr[i] > max )
		{
			max = arr[i];
		}
	}
	int count_max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == max )
		{
			count_max++;
		}
	}

	if ( (n - count_max) == 0 )
	{
		printf("0\n");
		return 0;
	}
	printf("%d\n",n - count_max);

	for (int i = 0; i < n; ++i)
	{
		if ( arr[i] != max)
		{
			printf("%d ",arr[i]);
		}
	}
	printf("\n");

}