#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int i = 1;
    k = 240 - k;
    int ans = 0;
    while( i*5 <= k ) {
        ans++;
        k -= i*5;
        i++;
    }
    cout << min(n, ans) << '\n';
    return 0;
}