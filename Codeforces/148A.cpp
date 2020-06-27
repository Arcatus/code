#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    bool z[d+1] = { };
    for(int i=k; i<=d; i+=k) {
        z[i] = true;
    }
    for(int i=l; i<=d; i+=l) {
        z[i] = true;
    }
    for(int i=m; i<=d; i+=m) {
        z[i] = true;
    }
    for(int i=n; i<=d; i+=n) {
        z[i] = true;
    }
    int cnt = 0;
    for(int i=1; i<=d; ++i) {
        if(z[i])cnt++;
    }
    cout << cnt << '\n';
    return 0;
}