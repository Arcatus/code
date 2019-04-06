#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <fstream>
#include <cmath>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	int x1,x2,y1,y2;

	for (int i = 0; i < n; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		cout << abs(x1-x2) + abs(y1-y2) << '\n';
	}
}