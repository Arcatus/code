#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
#include <vector>
//#include <string>

bool dp[1000][1000];

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	
	int total = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ( i == j || dp[i][j]) {
				continue;
			}
			dp[j][i] = dp[i][j] = true;

			total += nums[i] * nums[j];
		}
	}

	cout << total << '\n';
	return 0;
}