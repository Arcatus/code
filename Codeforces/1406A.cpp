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
        int a[101] = { };
        int x;
        for(int i = 0; i < n; ++i) {
            cin >> x;
            a[x]++;
        }
        bool ok = true;
        for(int i = 0; i <= 100 && ok; ++i) {
            if(a[i] == 0) {
                cout << 2*i << '\n'; break;
            } else if(a[i] == 1) {
                for(int j = i + 1; j <= 100; ++j) {
                    if(a[j] == 0) {
                        cout << i + j << '\n';
                        ok = false; break;
                    }
                }
            }
        }
    }
    return 0;
}