#include <bits/stdc++.h>

using namespace std;

bool orden[1000][1000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p, d, x;
    cin >> n >> p >> d;
    int mat[p][n];
    for(int i=0; i<p; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> x;
            mat[i][x] = j;
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            bool ok = true;            
            for(int k=0; k<p; ++k) {
                if ( abs( j - mat[k][i]) > d ) {
                    ok = false; break;
                }
            }
            orden[i][j] = ok;
        }
    }

    for(int i=0; i<n; ++i) { 
        for(int j=0; j<n; ++j) { 
            cout << orden[i][j] << ' ';
        } 
        cout  << '\n';
    }
    return 0;
}