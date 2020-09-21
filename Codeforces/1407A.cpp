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
        int a[n + 1];
        for(int i = 1; i <= n; ++i) cin >> a[i];
        int d = 0;
        for(int i = 1; i <= n; i+=2) {
            if(a[i] + a[i + 1] == 1) {
                if(a[i] == 1) a[i] = -1;
                else a[i + 1] = -1;
                d++;
            }
        }
        cout << n - d << '\n';
        for(int i = 1; i <= n; ++i) {
            if(a[i] != -1) cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}