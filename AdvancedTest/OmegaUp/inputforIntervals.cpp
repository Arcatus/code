//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>

#define n 1000000
#define m 1000
#define MAX_AI 1000
int main()
{
	srand (time(NULL));

	//int m = rand() % 1000;

	printf("%d\n",m);
	
	for (int i = 0; i < m; ++i)
	{
		int I = rand() % n ;

		int F = rand() % n ;

		if ( I > F )
		{
			std::swap(I,F);
		}

		printf("%d %d\n",I,F);
	}

	printf("%d\n",n);

	printf("%d\n",n);

	for(int i = 0; i < n; ++i)
	{
		int ai = (rand() % MAX_AI*2) - MAX_AI;

		printf("%d ",ai);
	}
	printf("\n");
}