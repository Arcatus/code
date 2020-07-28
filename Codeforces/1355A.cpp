#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    long long a, k;
    while(t--) {
        cin >> a >> k;
        long long ans = a;
        for(int i=1; i<k; ++i) {
            string s = to_string(ans);
            auto a = minmax_element(s.begin(), s.end());
            char x = *a.first;
            char y = *a.second;
            if( x == '0' || y == '0' ) break;
            ans += (long long) ((x - '0')*(y - '0'));
        }
        cout << ans << '\n';
    }
    return 0;
}