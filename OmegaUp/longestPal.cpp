#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100];

int lps(int l, int r) {
	if ( l == r ) {
		return 1;
	} else if( l > r ) {
		return 0;
	}
	if ( s[l] == s[r] ) {
		return lps(l+1,r-1) + 2;
	} else {
		int ans = max(lps(l+1,r), lps(l,r-1));
		return ans;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	int ans = lps(0,strlen(s)-1);

	cout << ans << '\n';
}