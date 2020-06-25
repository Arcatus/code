#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int f, c;
    cin >> f >> c;
    int a[f*c];
    for(int i=0; i<f*c; ++i) cin >> a[i];
    sort(a, a+f*c);
    int ans[f][c] = { };
    int cnt = 0;
    for(int i=0; i<c; ++i) {
        for(int j=0; j<f; ++j) {
            ans[j][i] = a[cnt++];
        }
    }
    for(int i=0; i<f; ++i) {
        for(int j=0; j<c; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}