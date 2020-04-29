#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n+1];
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    int v = *max_element(a+2,a+n+1);
    while(a[1] <= v ) {
        int pos = max_element(a+2,a+n+1)  - a;
        a[1] += 1;
        a[pos] -= 1;
        ans += 1;
        v = *max_element(a+2,a+n+1);
    }
    cout << ans << '\n';
    return 0;
}