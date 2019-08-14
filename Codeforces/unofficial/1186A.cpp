#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;

	cin >> n >> m >> k;

	if ( n <= m && n <= k ) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}