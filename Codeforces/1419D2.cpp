#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int b[n] = { };
    int i, j;
    for(i = n - 1, j = n - 1; i >= 0 && j >= 0; i-=2, j--) {
        b[i] = a[j];
    }
    for(i = n - 2; i >= 0 && j >= 0; i-=2, j--) {
        b[i] = a[j];
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        if(b[i] < b[i - 1] && b[i] < b[i + 1]) {
            ans++;
        }
    }
    // other allocation
    int c[n] = { };
    for(i = n - 2, j = n - 1; i >= 0 && j >= 0; i-=2, j--) {
        c[i] = a[j];
    }
    for(i = n - 1; i >= 0 && j >= 0; i-=2, j--) {
        c[i] = a[j];
    }
    int ans2 = 0;
    for(int i = 1; i < n - 1; i++) {
        if(c[i] < c[i - 1] && c[i] < c[i + 1]) {
            ans2++;
        }
    }
    if(ans2 > ans) {
        cout << ans2 << '\n';
        for(int i : c) cout << i << ' '; cout << '\n';
    } else {
        cout << ans << '\n';
        for(int i : b) cout << i << ' '; cout << '\n';
    }
    return 0;
}