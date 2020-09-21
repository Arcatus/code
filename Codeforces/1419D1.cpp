
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
    int ans = 0;
    for(int i = n - 2; i >= 1; i-=2) {
        ans++;
        swap(a[i], a[i - 1]);
    }
    cout << ans << '\n';
    for(int i: a) cout << i << ' '; cout << '\n';
    return 0;
}