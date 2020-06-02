#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    for(int i=a; i<=b; ++i) {
        ans += (int)pow(i,n);
    }
    cout << ans << '\n';
    return 0;
}