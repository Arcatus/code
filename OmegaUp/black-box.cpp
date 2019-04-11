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
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n, a, b, op;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> op;
		cin >> a >> b;
		if (op & 1)
		{
			if (a != 0 && b == 0 )
			{
				cout << "-1" << '\n';
			}	
			else
			{
				cout << "1000" << '\n';
			}
		}
		else
		{
			/*
			if (a == 0 && b != 0 )
			{
				cout << "0" << '\n';
			}
			else
			{
				cout << "1000" << '\n';
			}*/
			cout << "1000" << '\n';
		}
	}
}