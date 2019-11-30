#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string card;

	cin >> card;

	bool ans = false;
	string x;
	for (int i=0; i<5; ++i) {
		cin >> x;
		if ( x[0] == card[0] || x[0] == card[1] || x[1] == card[0] || x[1] == card[1] ) {
			ans = true;
			break;
		}
	}
	if ( ans ) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}