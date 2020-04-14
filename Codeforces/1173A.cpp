#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, z;

	cin >> x >> y >> z;

	if ( x > y+z ) {
		cout << "+\n";
	} else if ( y > x+z ) {
		cout << "-\n";
	} else if ( x == y && z == 0 ) {
		cout << "0\n";
	} else {
		cout << "?\n";
	}
}