#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    ll ans = INT_MAX;
    ll tmp = 0;
    for(int i = 0; i < k; ++i) {
        tmp += a[i];
    }
    ans = min(ans, tmp);
    int index = 1;
    for(int i = k; i < n; ++i) {
        tmp += a[i] - a[i - k];
        if(tmp < ans) {
            ans = tmp;
            index = i - k + 2;
        }
    }
    cout << index << '\n';
    return 0;
}