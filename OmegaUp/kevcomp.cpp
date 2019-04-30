#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>
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
	int a, b;
	for (int i=0; i<n;++i)
	{
		cin >> a >> b;

		if (a == b)
			cout << "NO ITZMAN" << '\n';
		else cout << max(a,b) << '\n';
	}

	return 0;
}