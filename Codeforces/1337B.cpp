#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, n, m;
    int t;
    cin >> t;
    while(t--) {
        cin >> x >> n >> m;
        while(x > 20 && n > 0) {
            x = x/2 + 10;
            n--;
        }
        while(m > 0 && x > 0) {
            x -= 10;
            m--;
        }
        if(x <= 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}