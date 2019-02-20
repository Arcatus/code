//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>

using namespace std;

int main()
{
	int n, busca;

	int arr[1000+1]{};

	scanf("%d",&n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}

	scanf("%d",&busca);

	sort(arr,arr+n);

	int *ini = lower_bound(arr,arr+n,busca);

	int *fin = upper_bound(arr,arr+n,busca);

	printf("%ld\n", fin - ini);
}