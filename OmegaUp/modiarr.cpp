//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int n, m, t;

	scanf("%d %d",&n,&m);

	int arr[n]{};

	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&t);
		arr[t]++;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}