#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	float ans = 0.0f;
	float x;
	for(int i=0; i<n; ++i) {
		cin >> x;
		ans+=x;
	}
	cout << ans/n << '\n';
}