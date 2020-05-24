#include <bits/stdc++.h>

using namespace std;

struct robot {
    int v, e;
};

int solve(int bomba, int robot ) {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int mat[n][n];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> mat[i][j];
        }
    }
    int r;
    cin >> r;
    robot robots[r];
    for(int i=0; i<r; ++i) {
        cin >> robots[i].v >> robots[i].e;
    }
    int ans = solve(0,0);
    cout << ans << '\n';
    return 0;
}