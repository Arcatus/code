#include <iostream>
#include <set>

using namespace std;

int botas[1000000+1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int x;
	for (int i=0; i<n; ++i) {
		cin >> x;
		botas[x]++;
	}
	int ans = 0;
	for (int i=0; i<=1000000; ++i) {
		ans += botas[i] % 2;
	}
	cout << ans << '\n';
}