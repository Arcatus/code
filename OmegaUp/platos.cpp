#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m[4][4];
    for(int i=0; i<4;++i) {
        for(int j=0; j<4; ++j) {
            cin >> m[i][j];
        }
    }
    int n;
    cin >> n;
    char opc[3];
    int rotos[4][4] = { };
    for(int i=0; i<n; ++i) {
        cin >> opc;
        rotos[opc[0]-'A'][opc[1]-'1']++;
    }
    int ans = 0;
    for(int i=0; i<4; ++i) {
        int v = 1 << 30;
        int total = 0;
        for(int j=0; j<4; ++j) {
            v = min(v, rotos[i][j]);
            total += m[i][j];
        }
        if (v) {
            ans += (total*v - 10*v);
            for(int j=0; j<4; ++j) {
                rotos[i][j] -= v;
                ans += rotos[i][j]*m[i][j];
            }
        } else {
            for(int j=0; j<4; ++j) ans += rotos[i][j]*m[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}