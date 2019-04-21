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
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i <n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr,arr+n);

	cout << arr[0] + arr[1]  << '\n' << arr[n-2] + arr[n-1] << '\n';

	return 0;
}