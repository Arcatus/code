#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	 
	string a, b;

	cin >> a;
	cin >> b;
	for_each(a.begin(), a.end(),[](char& c) {
		c = tolower(c);
	});
	for_each(b.begin(), b.end(),[](char& c) {
		c = tolower(c);
	});

	if ( a < b ) {
		cout << -1 << '\n';
	} else if ( a > b ) {
		cout << 1 << '\n';
	} else {
		cout << 0 << '\n';
	}
}