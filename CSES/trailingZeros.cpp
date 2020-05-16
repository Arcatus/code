#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int div = 5;
    int n;
    cin >> n;
    int ans = 0;
    while( div <= n ) {
        ans += n / div;
        div *= 5;
    }
    cout << ans << '\n';
    return 0;
}