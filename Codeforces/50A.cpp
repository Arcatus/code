#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> m >> n;

	if ( n == 1 && m == 1 ) {
		cout << 0 << '\n';
	} else if ( m >= 2 && m%2 == 0 )  {
		cout << (m/2)*n << '\n';
	} else if ( n >=2 && n%2 == 0 ) {
		cout << (n/2)*m << '\n';
	} else {
		cout << (max(n,m)/2)*min(n,m) + (min(n,m)/2) << '\n';
	}
}