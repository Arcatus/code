#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>
#include <vector>
//#include <string>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long n;

	cin >> n;
	long total=0;
	while( n >= 0 )
	{
		if (n >= 10 && n <= 100) total+=n;
		cin >> n;
	}

	cout << total << '\n';

	return 0;
}