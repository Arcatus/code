#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k=0;
    cin >> n;
    string ans;
    bool tablero[27][27];
    while( k++ < n ) {
        ans = "";
        cin >> p >> q;
        tablero[0][0] = true;
        ans += 'A';
        ans += '1';
        cout << "Scenario #" << k << ":\n";
        int steps = 0:
        while( steps < p*q ) {
            for(int i=0; i<8; ++i) {
                
            }
        }
        if ( steps < p*q ) {
            cout << "impossible\n";
        } else {
            cout << ans << '\n';
        }
        for(int i=0; i<q; ++i) {
           for(int j=0; j<p; ++j) {
               tablero[i][j] = false;
           }    
        }
    }
    return 0;
}