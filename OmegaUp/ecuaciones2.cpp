#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>
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
	int a, b, c;
	for (int i =0;i<n;++i)
	{
		cin >> a >> b >> c;		

		if ( (pow(b,2) - (4*a*c) ) >= 0)
		{
			cout << "SI" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}

	return 0;
}