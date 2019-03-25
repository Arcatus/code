//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

typedef long long ll;

int main()
{
	ll n;
	scanf("%lld",&n);

	ll fib[2];

	n++;

	//fib[0] = 0; // original
	fib[0] = 1;
	fib[1] = 1;

	for (ll i = 2 ; i <= n; ++i)
	{
		//printf("%lld %lld %lld\n",i%2,(i-1)%2,(i-2)%2);
		fib[ i%2 ] = fib[ (i-1)%2 ] + fib[ (i-2)%2 ];
	}
	if (n <= 1)
	{
		printf("1\n");
	}
	else
	{
		printf("%lld\n",fib[ n%2 ] % 1000000007 );
	}
}