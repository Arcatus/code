#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if( n >= k*k) {
            if(n % 2 == k % 2 ) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}