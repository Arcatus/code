//#include <iostream>
#include <stdio.h>
//#include <string>
//#include <algorithm>
//#include <string>


int BIT[500000];

int query(unsigned int x);

int main()
{
	short m, Ai;
	int n; int I; int F;
	fpos_t intervals;

	scanf("%hi",&m);	

	short t_m = m + 1;

	fgetpos(stdin, &intervals);

	while( t_m > 0 )
	{
		char t = getchar();
		if ( t == '\n')
		{
			t_m--;
		}
	}

	scanf("%d",&n);

	for(int i = 1; i <= n; ++i)
	{
		scanf("%hi",&Ai);

		for(int k = i; k <= n; k += k&-k)
		{
			BIT[k] += Ai;
		}
	}

	fsetpos(stdin,&intervals);

	for ( int i = 0; i < m; ++i)
	{
		scanf("%d %d",&I,&F);

		printf("%d\n", query(F) - query(I));
	}
}

int query(unsigned int x)
{
	int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}