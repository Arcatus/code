#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;   
    int n, k;
    while(t--) {
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        int b[n];
        for(int i = 0; i < n; ++i) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n, [](int x, int y){
            return x > y;
        });
        int p1 = 0, p2 = 0;
        int inter = 0;
        while(p2 < n && inter < k) {
            if(a[p1] < b[p2]) {
                swap(a[p1], b[p2]);
                p1++; p2++; inter++;
            } else {
                p2++;
            }
        }
        int ans = accumulate(a, a + n, 0);
        cout << ans << '\n';
    }
    return 0;
}