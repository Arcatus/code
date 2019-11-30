#include <cstdio>
#include <algorithm>

using namespace std;

long long memoria[1000000];

long long collatz(long long k)
{
	if (k == 1)
		return 1;
	if ( k < 1000000 ) {
		if ( memoria[k] == 0 ) {
			if ( k & 1 ) {	
				memoria[k] = 1 + collatz( 3*k + 1 );
			} else {
				memoria[k] = 1 + collatz( k >> 1 );
			}			
		}
		return memoria[k];
	} else {
		if ( k & 1 ) {	
			return 1 + collatz( 3*k + 1 );
		} else {
			return 1 + collatz( k >> 1 );
		}
	}
}

int main()
{
	int i, j;
	while(scanf("%d %d",&i,&j) != EOF) {
		long long p = -1;
		for (long long a=min(i,j); a<=max(i,j); ++a ) {
			long long ans = collatz(a);
			p = max(p,ans);
		}
		printf("%d %d %lld\n",i,j,p);
	}
}