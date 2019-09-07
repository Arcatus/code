#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;

	int n;

	cin >> n;
	int x = 0;
	for(int i=0; i<n; ++i) {
		cin >> s;
		if ( s[1] == '+' ) {
			x +=1;
		} else {
			x -=1;
		}
	}
	cout << x << '\n';
}