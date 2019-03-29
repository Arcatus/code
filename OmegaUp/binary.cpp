//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

unsigned int countSetBits(int n) 
{ 
    unsigned int count = 0; 
    while (n) 
    { 
	    n &= (n-1);
	    count++; 
    }
    return count;
}

long setBitNumber(long n)
{ 
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16;

    n = n + 1; 

    return (n >> 1);
}

int main()
{
	int n;
	scanf("%d",&n);

	long msb = setBitNumber(n);

	int bits = countSetBits(n);

	long mayor = msb;
	long menor = msb;

	for (int i = 0; i < bits-1; ++i)
	{	
		mayor |= (mayor >> 1);
	}

	for (int i = 0; i < bits-1; ++i)
	{
		menor |= (1<<i);
	}
	printf("%ld %ld\n",mayor, menor);
}