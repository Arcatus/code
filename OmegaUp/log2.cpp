#include <iostream>
#include <cstdio>

int main()
{
	uint32_t bitmask = 0x0001;

	uint32_t n;

	scanf("%d",&n);

	uint8_t count = 0;

	while( ! (bitmask == n ) )
	{
		bitmask = ( bitmask << 1 );
		count++;
	}
	printf("%d\n",count);
}