#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int min_v = INT_MAX;
    int max_v = INT_MIN;
    int p1, p2;
    for(int i = 0; i < n; ++i) {
        if ( a[i] > max_v) {
            max_v = a[i];
            p1 = i;
        }
    }
    for(int i = n - 1; i >= 0; --i) {
        if ( a[i] < min_v) {
            min_v = a[i];
            p2 = i;
        }
    }
    int ans = p1 + (n - (p2 + 1));
    if (p1 > p2) ans--;
    cout << ans << '\n';
    return 0;
}