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
        int a[n];
        for(int i = 0;  i < n; ++i) cin >> a[i];
        int domi = -1;
        for(int i = 0; i < n; ++i) {
            domi = max(domi, a[i]);
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(domi == a[i]) {
                cnt++;
            }
        }
        if(cnt < n) {
            for(int i = 0; i < n; ++i) {
                if(i == 0) {
                    if(a[i] == domi && domi > a[i + 1]) {
                        cout << i + 1 << '\n'; break;
                    }
                } else if(i == n - 1) {
                    if(a[i] == domi && domi > a[i - 1]) {
                        cout << i + 1 << '\n'; break;
                    }
                } else {
                    if(a[i] == domi && (domi > a[i - 1] || domi > a[i + 1])) {
                        cout << i + 1 << '\n'; break;
                    }
                }
            }
        } else {
            cout << -1 << '\n';
        }   
    }
    return 0;
}