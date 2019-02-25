//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{	
	int n, k;

	scanf("%d %d",&n,&k);

	int arr[n];

	for (int i = 0; i < n ; ++i)
	{
		scanf("%d",&arr[i]);
	}
	int max = 0; int tmp;

	for(int i = 0; i <= n - k; ++i) 
	{
		tmp = 0;
		for(int j = 0; j < k; ++j)
		{
			tmp += arr[j+i];
		}
		if (tmp > max)
		{
			max = tmp;
		}		
	}
	printf("%d\n",max);
}