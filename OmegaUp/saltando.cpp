//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>
//#include <cstdlib>

short n = 0;
short posicion = 0;
short saltos = 0;
short pre = 0;

int main()
{
	scanf("%hi",&n);
	short arr[n];

	for(short i = 0; i < n; ++i)
	{
		scanf("%hi",&arr[i]);
	}

	while( arr[posicion] != 0x00 )
	{
		pre = posicion;
		posicion = posicion + arr[posicion];
		saltos = saltos + 1;
		arr[pre] = 0x00;
	}

	if ( posicion + 1 == n )
	{
		printf("%hi\n",saltos);
	}	
	else 
	{
		printf("-1\n");
	}
}