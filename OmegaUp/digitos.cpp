//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int n;
	scanf("%d",&n);

	if( n < 10)
	{
		printf("%d\n",n);
	}
	else if( n < 100)
	{
		int t = n - 9;
		printf("%d\n", t*2 + 9 );
	}
	else if ( n < 1000)
	{
		int t1 = n - 99;
		printf("%d\n",t1*3 + 90*2 + 9);
	}
	else if ( n < 10000)
	{
		int t0 = n - 999;

		printf("%d\n",t0 * 4 + 900*3 + 90*2 + 9);
	}	
	else if ( n < 100000 )
	{
		int t0 = n - 9999;

		printf("%d\n", t0*5 + 9000 * 4 + 900*3 + 90*2 + 9);
	}
	else if ( n < 1000000 )
	{
		int t0 = n - 99999;

		printf("%d\n", t0*6 + 90000*5 + 9000 * 4 + 900*3 + 90*2 + 9);
	}
	else if ( n < 10000000 )
	{
		int t0 = n - 999999;

		printf("%d\n", t0*7+ 900000*6 + 90000*5 + 9000 * 4 + 900*3 + 90*2 + 9);	
	}
	else if ( n < 100000000 )
	{
		int t0 = n - 9999999;

		printf("%d\n", t0*8 + 9000000*7 + 900000*6 + 90000*5 + 9000 * 4 + 900*3 + 90*2 + 9);	
	}
	else if ( n < 1000000000 )
	{
		int t0 = n - 99999999;

		printf("%d\n", t0*9 + 90000000*8 + 9000000*7 + 900000*6 + 90000*5 + 9000 * 4 + 900*3 + 90*2 + 9);
	}
}