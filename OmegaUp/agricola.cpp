#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

typedef long long lld;

int main()
{
	int n;
	scanf("%d",&n);

	lld res = 0;

	lld a , b;

	for (int i = 0; i < n; ++i){
		scanf("%lld %lld",&a,&b);
		res += a*b;
	}

	printf("%lld",res);
}
