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

	int n, a, b;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		if (a > 0 && b > 0)
		{
			cout << "I" << '\n';
		}
		else if (a > 0 && b < 0)
		{
			cout << "IV" << '\n';
		}
		else if( a < 0 && b > 0)
		{
			cout << "II" << '\n';
		}
		else
		{
			cout << "III" << '\n';
		}
	}
	return 0;
}