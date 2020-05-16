#include <bits/stdc++.h>

using namespace std;

int f(int n) {
    for(int i=2; i*i <= n; ++i) {
        if ( n % i == 0 ) {
            return i;
        } 
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    long long n, k, u;
    while(t--) {
        cin >> n >> k;
        if (n % 2 == 0 ) {
            cout << k*2 + n << '\n';
        } else {
            long long ans = n;
            bool trick = false;
            for(int i=0; i<k; ++i) {
                u = f(n);
                if ( u % 2 == 0) {
                    trick = true;
                    cout << (k-i)*2 + ans << '\n'; break;
                }
                ans += u;
                n = ans;
            }
            if (!trick) cout << ans << '\n';
        }
    }
    return 0;
}