#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;

	cin >> s;

	vector<int> nums;

	for(int i=0; i<s.size(); i+=2) {
		nums.push_back(s[i]-'0');
	}
	sort(nums.begin(),nums.end());

	for(int i=0; i< nums.size()-1; ++i){
		cout << nums[i] << '+';
	}
	cout << nums[nums.size()-1];
}