//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

typedef long long ll;

int main()
{
	int n;
	scanf("%d",&n);

	ll fibo[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	ll res = fibo[n+1];

	for (int i = 0 ; i < n-1 ; ++i)
	{
		fibo[ n + 1 ] *= res;
	}

	printf("%lld\n", fibo[n+1]);
}
