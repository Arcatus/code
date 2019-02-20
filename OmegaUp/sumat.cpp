//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int n;

	scanf("%d",&n);	

	int k = 0;

	int res = 0;

	do
	{
		k++;
		res += 7 + k;
	}
	while( res < n );

	printf("%d\n",k);
}