#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>

#define q 100
#define n 10000000
#define MAX_AI 1245

#define k 1

using namespace std;

int main()
{
	srand (time(NULL));

	printf("%d\n",q);

	for (int i = 0; i < q; ++i )
	{
		int a = (rand() % n)+3;

		while( a%2 == 1)
		{
			a+=1;
		}
		cout << a << '\n';
	}
	cout << '\n';
}