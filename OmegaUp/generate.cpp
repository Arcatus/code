#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>

#define n 1000
#define m 1000
#define MAX_AI 1000

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);

	cout << n << '\n';

	for (int i = 1; i <= n; ++i )
	{
		int a = rand() % MAX_AI;
		cout << a << ' ';
	}
	cout << '\n';
	cout << m << '\n';
	for (int i = 0; i < m; ++i ) {
		int a = rand() % n;
		int b = rand() % n;
		if ( a > b ) swap(a,b);
		cout << a << " " << b << '\n';
	}
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