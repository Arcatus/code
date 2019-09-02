#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	set<unsigned int> nums;

	unsigned int n, k;

	cin >> n >> k;

	unsigned int x;
	for(int i=0; i<n; ++i) {
		cin >> x;
		nums.insert(x);
	}
	int ans = 0;
	for(unsigned int i: nums) {
		ans += ( nums.find(i+k) != nums.end() );
	}
	cout << ans << '\n';
}