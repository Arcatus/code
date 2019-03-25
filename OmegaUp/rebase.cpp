//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>

int main()
{
	int n, t;

	scanf("%d",&n);

	int arr[n];

	for (int i=0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}

	std::sort( arr, arr + n );

	int rebases = 0;
	
	

	printf("%d\n",rebases);

}