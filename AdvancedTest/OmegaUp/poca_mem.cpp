//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

/*
	1.39MB at only storage the intervals

	1.44MB	 -> 10 		50%
	1.5MB	 -> 100000	50%
	>1.75	 -> 800000  50%
*/

int query(unsigned int x, int BIT[])
{
	int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}

int main()
{
	short intervalos;

	scanf("%hi",&intervalos);

	int n; // 0 <= N <= 1,000,000,
	short Ai; // -1000 <= Ai <= 1000

	unsigned int ARr[intervalos][2];
	
	// I should delet this

	for ( int i = 0; i < intervalos;++i)
	{
		scanf("%d %d",&ARr[i][0],&ARr[i][1]);
	}

	scanf("%d",&n);

	int BIT[n+1]{};

	for(int i = 1; i <= n; ++i)
	{
		scanf("%hi",&Ai);

		for(int k = i; k <= n; k += k&-k)
		{
			BIT[k] += Ai;
		}
	}
/*
	for(const short& i: BIT)
	{
			printf("%hi ",i);
	}printf("\n");
*/
	for (int i = 0; i < intervalos; ++i )
	{
		printf("%d\n", query(ARr[i][1], BIT ) - query(ARr[i][0], BIT ) );
	}
}