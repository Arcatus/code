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

int arr[20 + 1][20 + 1];
int brr[20 + 1][20 + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i<n ; ++i )
	{
		for (int j = 0; j<m ; ++j )
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i<m ; ++i )
	{
		for (int j = 0; j<n; ++j )
		{
			brr[i][j] = arr[j][i];
		}
	}

	for (int i = 0; i<m ; ++i )
	{
		for (int j = 0; j<n; ++j )
		{
			cout << brr[i][j] << ' ';
		}
		cout << '\n';
	}
}