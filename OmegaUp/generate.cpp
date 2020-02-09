#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <unordered_set>

#define n 5
#define m 1000
#define MAX_AI 3

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);

	cout << n << '\n';

	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<i; ++j) {
			cout << 3 << ' ';
		}
		cout << '\n';
	}

}