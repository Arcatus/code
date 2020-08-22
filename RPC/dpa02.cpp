// TLE 46 sec 

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(ll n) {
    ll acc = 1LL;
    for(ll i = 2; i*i < n; ++i) {
        if (n % i == 0) {
            if (i != n/i) {
                acc += i;
                acc += n / i;
            } else {
                acc += i;
            }
        }
        if(acc > n) break;
    }
    if (acc < n) {
        return -1;
    } else if(acc == n) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll n;
    while(t--) {
        cin >> n;
        int opc = solve(n);
        if ( opc == -1 ) {
            cout << "deficient\n";
        } else if(opc == 0) {
            cout << "perfect\n";
        } else {
            cout << "abundant\n";
        }
    }
    return 0;
}