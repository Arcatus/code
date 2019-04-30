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
	int brr[n];

	for (int i = 0; i < n; ++i)
	{	
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i)
	{	
		cin >> brr[i];
	}

	sort(arr,arr+n);
	sort(brr,brr+n);

	int index0=0, index1=0;

	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[index0]==brr[index1])
		{
			index0++;
		}
		else if ( arr[index0] > brr[index1])
		{
			res += arr[index0];
			index0++;
			index1++;
		}
		else
		{
			index0++;
		}
	}

	cout << res << '\n';

	
	return 0;
}