#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int arr[n];

	for(int &i: arr) {
		cin >> i;
	}

	sort(arr, arr+n, [](const int& a, const int& b){
		return a > b;
	} );
	
	long long remain = accumulate(arr, arr+n, 0);

	int i = 0;
	long long ans = 0;
	while( ans <= remain/2 && i < n ) {
		ans += arr[i];
		i++;
	}
	cout << i << '\n';
}