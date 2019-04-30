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
	const int arr[] = { 0,0,0,5,5,5,6,7,7,7,7 };

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int t;
	for (int i=0;i<n;++i)
	{
		cin >> t;
		cout << arr[t] << '\n';
	}

	return 0;
}