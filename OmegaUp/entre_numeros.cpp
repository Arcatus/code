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

	int a, b;
	cin >> a >> b;

	if (a < 0 || b < 0 || a >= b )
	{
		cout << "Error";
	}
	else
	{
		if (a & 1)
		{
			for (int i = a+1; i < b; ++i)
			{
				if (i%2==0)
				{
					cout << i << ' ';
				}
			}
		}
		else
		{
			for (int i = a+1; i < b; ++i)
			{
				if (i & 1)
				{
					cout << i << ' ';
				}
			}
		}
	}
	cout << '\n';

	return 0;
}