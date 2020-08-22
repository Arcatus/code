#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(int n) {
    ll acc = 0;
    for(int i = 1; i < n; ++i) {
        if (n % i == 0) {
            acc += i;
        }
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
    int n;
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