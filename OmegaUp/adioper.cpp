//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int a, b ,c;

	scanf("%d %d %d",&a,&b,&c);

	if ( a*b == c )
	{
		printf("*\n");
	}
	else if ( a+b == c )
	{
		printf("+\n");
	}
	else if ( a/b == c )
	{
		printf("/\n");
	}
	else if ( a-b == c )
	{
		printf("-\n");
	}
	else
	{	
		printf("D:\n");
	}


}