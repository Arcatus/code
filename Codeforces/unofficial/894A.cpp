#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char s[100+1];
/* Recursive implementation
int qaq(int i, string k) {
	if ( i == n+1 ) {
		return 0;
	}
	if ( k.compare("QAQ") == 0 ) { 
		return 1;
	}
	int ans=0;
	if ( k.size() < 3 ) {
		ans += qaq(i+1,k+s[i]) + qaq(i+1,k);

		// interpretacion
		qaq(i,k) <- qaq(i+1,k+s[i]) + qaq(i+1,k)

	}
	return ans;
}
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	n = strlen(s);

	int dp[3] = { 0, 0, 0 };

	// dp[0] <- q
	// dp[1] <- qa
	// dp[2] <- qaq

	for(int i=0; i<=n; ++i) {
		if ( s[i] == 'Q' ) {
			dp[0] += 1;
			dp[2] += dp[1];
		} else if ( s[i] == 'A') {
			dp[1] += dp[0];			
		}
	}	
	cout << dp[2] << '\n';
	/*
	int ans = qaq(0,"");
	cout << ans << '\n';
	*/
}