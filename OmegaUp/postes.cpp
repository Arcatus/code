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

int arr[1000000+1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;

	int n;
	cin >> n;

	for (int i=0;i<n;++i)
	{
		cin >> arr[i];
	}

	sort(arr,arr+n);

	long long result = 1000001LL;
	
	for (int i=k-1;i<n;i++)
	{
		result = min(result,(long long)arr[i]-arr[i-k+1]);
	}
	cout << result << '\n';
	return 0;
}