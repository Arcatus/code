/*
	sumprefix.cpp
*/

//#include <iostream>
#include <stdio.h>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int n;
	scanf("%d",&n);

	int sumprefix = 0;

	short arr[n+1]; short t;

	arr[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		scanf("%hi",&t);

		sumprefix+=t;

		arr[i] = sumprefix;
	}
	int m;
	scanf("%d",&m);
	int i, u;

	for(int k = 0; k < m; ++k)
	{
		scanf("%d%d",&i,&u);

		printf("%d\n", arr[u+1] - arr[i]);
	}
}