#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <unordered_set>

#define n 50
#define m 150
#define MAX_AI 1000000

using namespace std;

int main()
{
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cout.tie(0);

	cout << n << '\n';

	for(int i=0; i<n; ++i) {
		int a= rand()%m + 1;
		cout << a << ' ';
	}
	cout <<'\n';
}