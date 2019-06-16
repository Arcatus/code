#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>

#define m 1000
#define n 10
#define MAX_AI 1245

#define k 1

using namespace std;

int main()
{
	//printf("const char *fibos[] = {");

// 65-90
	srand (time(NULL));

	printf("%d\n",n);

	for (int i = 0; i < n; ++i )
	{
		int a=(rand()%9999)+1;
		int b=(rand()%9999)+1;
		int z=(rand()%9999)+1;
		cout << a << " " << b << " " << z << '\n';
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