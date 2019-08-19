#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>

#define n 50000
#define MAX_AI 1245

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);

	srand (time(NULL));

	int r = rand() % n;

	long long k = 1000000LL;

	cout << n << " " << r << " " << k << '\n';

	int a_i = INT_MAX;

	for (int i = 0; i < n; ++i )
	{
		int a = rand() % a_i;
		cout << a << ' ';
	}
	cout << '\n';
	/*
	printf("%d %d\n",n,m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int ai = (rand() % MAX_AI);
			printf("%d ",ai);		
		}printf("\n");
	}

	printf("%d\n",k);

	printf("V\n");

	/*
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
	*/

}