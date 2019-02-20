#include <iostream>
#include <cstdio>
#include <cstdint>
//#include <string>
//#include <algorithm>
//#include <string>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

int main()
{
	int a, b, c;

	uint64_t n = 0;

	scanf("%d %d %d",&a,&b,&c);

	for(int i = 1; i <= a; i++)
	{
		if( i%2==1 )
		{
			n+=i;
		}
	}

	//printf("%" PRIu64"\n", n);

	int pot2[]=
	{
		1 , 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048
	};

	int k = 0;

	while( pot2[k] <= b)
	{
		n-=pot2[k];
		k++;
	}

	while( n%c==0 )
	{
		n = n / c;
	}

	//printf("last:%ld\n",n);
	printf("%" PRIu64"\n", n);

}