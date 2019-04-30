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
int a[1000000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int t;
	for (int i=0;i<n;++i)
	{
		cin >> t;
		a[t]++;
	}
	int k;
	cin >> k;
	cout << a[k] <<'\n';

	return 0;
}