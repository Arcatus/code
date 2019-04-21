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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	int t, x=0;

	for (int i = 0 ; i < n; ++i)
	{
		cin >> t;
		x+=t;
	}

	if ( x <= m)
	{
		cout << "SI" << '\n';
	}	
	else
		cout << "NO" << '\n';
	return 0;
}