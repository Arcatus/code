#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>

#define q 100
#define n 50
#define MAX_AI 1245

#define k 15

using namespace std;

int main()
{
	srand (time(NULL));

	printf("%d ",n);
	printf("%d\n",k);

	for (int i = 1; i <= n*n; ++i )
	{
		int a = (rand() % k)+1;
		cout << a << ' ';
		if ( i%n == 0 ) cout << '\n';
	}
	cout << '\n';
}