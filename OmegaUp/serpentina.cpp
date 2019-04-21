#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int arr[20][20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	int contador=1;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = contador++;
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i%2==0) {
				cout << arr[i][j]<<' ';
			} else {
				cout << arr[i][n-1-j] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}