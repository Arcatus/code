//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>

#define n 10
#define MAX_AI 90


int main()
{
	srand (time(NULL));

	printf("%d\n",n);

	for(int i = 0; i < n; ++i)
	{
		int ai = (rand() % MAX_AI);

		printf("%d ",ai);
	}

	printf("\n");
	for(int i = 0; i < n; ++i)
	{
		int ai = (rand() % MAX_AI);

		printf("%d ",ai);
	}

	printf("\n");
	for(int i = 0; i < n; ++i)
	{
		int ai = (rand() % MAX_AI);

		printf("%d ",ai);
	}
	printf("\n");
}