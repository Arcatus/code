#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	string s;
	cin >> s;

	if ( n == 1 ) {
		cout << 0 << '\n';
		return 0;
	}else if ( n == 2) {
		if ( s[0] != s[1]) cout << 0 << '\n';
		else {
			cout << 1 << '\n';
		}
		return 0;
	}
	int i=1;
	int ans = 0;
	while( i < n ) {
		if ( s[i-1] == s[i] ) {
			ans += 1;
		}
		if ( i < n-1 && s[i] == s[i+1] ) {
			ans += 1;
		}
		i+=2;
	}
	cout << ans << '\n';
}