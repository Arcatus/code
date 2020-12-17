#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

int n;
int a[100+5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int acc[n + 5] = {};
    acc[0] = a[0];
    for(int i = 1; i < n; ++i) {
        acc[i] = acc[i - 1] + a[i];
    }
    int adder = 0;
    for(int i = 0; i < n; ++i) {
        adder = max(adder, acc[i]);
    }
    int ans = 100;
    cout << ans+adder << '\n';
    return 0;
}