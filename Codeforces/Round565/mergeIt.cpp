#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long t, n, input;

	long long res;

	cin >> t;

	for (int i = 0; i< t; ++i) {
		cin >> n;
		vector<long long> nums;
		res = 0;

		for (int j=0; j < n; ++j) {
			cin >> input;
			if (input % 3 == 0) {
				res+=1;
			}
			else {
				nums.push_back(input);
			}
		}

		for (int i=0; i < nums.size(); ++i) {	
			if (nums[i] != -1) {
			for (int j=i+1;j< nums.size();++j) {
				if (nums[j] == -1) continue;
				long long ans = nums[i] + nums[j];
				if ( ans % 3 == 0 && ans > 0) {
					res += 1;
					nums[i] = nums[j] = -1;
					goto next1;
				}
			}}
			next1:;
		}
		for (int i=0;i<nums.size();++i) {
			if (nums[i] != -1) {
			for (int j=i+1;j<nums.size();++j) {
				if (nums[j] == -1) continue;
				for (int k=j+1;k<nums.size();++k) {
					if (nums[k] == -1) continue;
					long long ans = nums[i] + nums[j] + nums[k];
					if ( ans % 3 == 0 && ans > 0) {
						res += 1;
						nums[i] = nums[j] = nums[k] = -1;
						goto next2;
					}
				}
			}}
			next2:;
		}		
		cout << res << '\n';
	}
	return 0;
}