#include <iostream>
//#include <cstdio>
//#include <fstream>
#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
#include <string>

using namespace std;


//typedef unsigned long long llu;
//typedef vector<int> vi;

int mat[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<string,int> tabla;

	string buffer;
	int n;
	cin >> n;
	for (int i = 0; i <n; ++i)
	{
		cin>>buffer;
		tabla.emplace(buffer,i);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}

	int casos;
	cin >> casos;

	int x, y;

	for (int i =0; i< casos;++i)
	{
		cin >> buffer;
		x = tabla[buffer];
		cin >> buffer;
		y = tabla[buffer];

		cout << mat[x][y] << '\n';
	}
	return 0;
}