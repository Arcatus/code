#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; string s; ll cnt=0;
    cin >> s >> n;
    for(int i=0; i<s.size(); ++i) {
        if (s[i] == 'E') cnt++;
    }
    ll ans = (( n*(n+1) ) / 2)*cnt;
    cout << ans << '\n';
    return 0;
}