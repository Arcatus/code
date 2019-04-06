//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int a, b;
	scanf("%d %d",&a,&b);

	if (a > b)
		while( b < a ) b = (b << 1);
	else
		while( a < b ) a = (a << 1);

	printf((a==b)?"felizmil":"tristemil");
}