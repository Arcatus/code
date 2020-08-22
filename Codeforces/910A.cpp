#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    string s;
    cin >> n >> d >> s;
    ll dp[n + 5] = { };
    for(int i = 0; i < n + 5; ++i) dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i = 1; i <= d; ++i) {
        if(s[i] == '1') dp[i] = 1;
    }
    for(int i = d + 1; i < n; ++i) {
        if(s[i] == '1') {
            for(int j = i; j >= i - d; --j) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    cout << (dp[n - 1] != INT_MAX ? dp[n - 1] : -1) << '\n';
    return 0;
}