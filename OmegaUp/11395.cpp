#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int m[n][n];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> m[i][j];
        }
    }
    int le = 0;
    int ri = n - 1;
    bool ok = true;
    for(int i=0; i<n && ok; ++i) {
        for(int j=le; j<n-le && ok; ++j) {   
            if ( m[i][j] != i || m[j][i] != i) {
                ok = false;
            }
        }
        for(int j=ri; j>=le && ok; --j) {
            if ( m[i][j] != i || m[j][i] != i) {
                ok = false;
            }
        }
        le++; ri--;
    }
    cout << ok << '\n';
    return 0;
}