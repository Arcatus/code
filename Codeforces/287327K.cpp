#include <bits/stdc++.h>

using namespace std;

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     int t;
     cin >> t;
     string s, ans;
     while(t--) {
     	cin >> s;
     	ans = s[0];
     	int n = s.size();
	for(int i = 1; i < n - 1; i+=2) {
	     ans += s[i];
	}
	ans += s[n - 1];
	cout << ans << '\n';
     }
     return 0;
}
