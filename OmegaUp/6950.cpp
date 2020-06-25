#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    int mat[11][11];
    for(int i=1; i<11; ++i) {
        for(int j=1; j<11; ++j) {
            mat[i][j] = 2;
        }
    }
    int a, b, c, d, e, f;
    for(int i=0; i<k; ++i) {
        cin >> a >> b >> c >> d >> e >> f;
        for(int i=1; i<11; ++i) {
            mat[a][i] = 1;
            mat[b][i] = 1;
            mat[c][i] = 1;
            mat[i][d] = 1;
            mat[i][e] = 1;
            mat[i][f] = 1;
        }
        for(int i=1; i<11; ++i) {
        for(int j=1; j<11; ++j) {
            mat[i][j]++;
        }
    }
    }
    for(int i=1; i<11; ++i) {
        for(int j=1; j<11; ++j) {
            cout << mat[i][j]-1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}