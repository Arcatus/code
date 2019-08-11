//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int n, m;
	scanf("%d %d",&n,&m);

	int tiempo = 0;

	while( n <= m)
	{
		n *= 3;
		m *= 2;
		tiempo++;
	}	
	printf("%d\n",tiempo);
}