#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    if (n == 0) cout << 0 << '\n';
    else {
        long long ans = (n-1)*(1LL << n-1);
        cout << ans << '\n';
    }
    return 0;
}