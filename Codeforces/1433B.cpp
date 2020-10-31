#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        bool a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        int p1 = 0, p2 = n - 1;
        while(!a[p1]) {
            p1++;
        }
        while(!a[p2]) {
            p2--;
        }
        int ans = 0;
        for(int i = p1; i < p2; ++i) {
            ans += (a[i]==false);
        }
        cout << ans << '\n';
    }
    return 0;
}