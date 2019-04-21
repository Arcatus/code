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

	int x;
	cin >> x;

	int gasto=0;
	int t;
	for (int i =0; i<7; ++i)
	{	
		cin >> t;
		if (t>x)gasto++;
	}

	cout << gasto << '\n';
	return 0;
}