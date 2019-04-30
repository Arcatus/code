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
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i=0;i<n;++i)
	{
		cin >> arr[i];
	}

	auto it = max_element(arr.begin(),arr.end());

	int res = *it * (n + 2);

	if (res & 1)
		cout << "pepperoni" << '\n';
	else 
		cout << "hawaiiana" << '\n';
	return 0;
}