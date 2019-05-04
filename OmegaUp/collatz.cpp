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

	int n;
	cin >> n;

	int contador=1;

	while( n!=1 )
	{
		contador++;
		if (n & 1)
			n = 3*n + 1;
		else
			n = n>>1;
	}

	cout << contador << '\n';

	return 0;
}