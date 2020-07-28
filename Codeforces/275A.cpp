#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int mat[3][3];
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> mat[i][j];
        }
    }
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    bool ans[3][3] = { };
    memset(ans, true, sizeof ans);
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            while(mat[i][j]) {
                ans[i][j] = !ans[i][j];
                for(int k = 0; k < 4; ++k) {
                    if( i + dx[k] >= 0 && j + dy[k] < 3 && i + dx[k] < 3 && j + dy[k] >= 0 ) {
                        ans[i + dx[k]][j + dy[k]] = !ans[i + dx[k]][j + dy[k]];
                    }
                }
                mat[i][j]--;
            }
        }
    }
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}