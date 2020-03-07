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
#define m 1000
#define MAX_AI 3

using namespace std;

int main()
{
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cout.tie(0);

	cout << n << '\n';

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if ( i == j) cout << '0' << ' ';
			else cout << rand()%100 << ' ';
		}
		cout << '\n';
	}

}