#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if ( k >= n ) {        
        cout << 1 << " " << n << '\n';
    } else {
        int last = n % k;
        int cnt = (n / k);
        if (last == 0) {
            cout << cnt << " " << k << '\n';
        } else {
            cout << cnt+1 << " " << last << '\n';
        }
    }
    return 0;
}