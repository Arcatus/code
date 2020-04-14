#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;

	cin >> x;

	if ( x > 5 ) {
		int step = x/5;
		if ( x % 5 == 0 ) {
			cout << step << '\n';
		} else {
			cout << step + 1 << '\n';
		}
	} else {
		cout << 1 << '\n';
	}
}