#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n);
    int ans1 = 0;
    int ans2 = 0;
    int tmp;
    for(int i=0; i<n; i+=2) {
        tmp = abs(a[i] - a[i+1]);
        ans1 += min(tmp, 24 - tmp);
    }
    for(int i=1; i<n-1; i+=2) {
        tmp = abs(a[i] - a[i+1]);
        ans2 += min(tmp, 24 - tmp);
    }
    ans2 += min(abs(a[n-1] - a[0]), 24 - abs(a[n-1] - a[0]));
    cout << min(ans1, ans2) << '\n';
    return 0;
}
