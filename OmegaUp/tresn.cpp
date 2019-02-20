//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int n;

	scanf("%d",&n);

	int contador = 0;

	int max = n;

	while( n != 1)
	{
		if ( n%2 == 0 )
		{
			n /= 2;
		}
		else
		{
			n = n*3 + 1;
		}
		if ( n > max)
		{
			max = n;
		}
		contador++;
	}

	printf("%d %d\n",contador,max);

}