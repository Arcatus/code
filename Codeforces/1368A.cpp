#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int a, b, n;
    int ans = 0;
    int cnt;
    while(t--) {
        cin >> a >> b >> n;
        cnt = 0;
        while(ans <= n) {
            cnt++;
            ans = (a+b);
            a = max(a,b);
            b = ans;
        }
        ans = 0;
        cout << cnt << '\n';
    }
    return 0;
}