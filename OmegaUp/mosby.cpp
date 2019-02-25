//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>

int mosby(int n, int m)
{
	int ret = 1;

	if (n == m)
		return 1;

	while(  ! (m == 1 && n == 1 ))
	{
		if ( n > m )
		{
			std::swap(n,m);
		}
		m = m - n;
		ret += 1;
	}
	return ret;
}

int main()
{
	int n, m;
	scanf("%d %d",&n,&m);

	printf("%d\n",mosby(n,m));
}