#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, k;
    while(t--) {
        cin >> n >> k;
        if (n < k) {
            cout << k - n << '\n';
        } else {
            if (n % 2 == k % 2) {
                cout << 0 << '\n';
            } else {
                cout << 1 << '\n';
            }
        }
        
    }
    return 0;
}