#include <bits/stdc++.h>

using namespace std;
struct celda{
    int blancos, amarillos;    
};
celda operator+(celda a, celda b) {
    return { a.blancos + b.blancos, a.amarillos + b.amarillos };
}
celda operator-(celda a, celda b) {
    return { a.blancos - b.blancos, a.amarillos - b.amarillos };
}
celda ama[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d;
    cin >> d;       
    int mat[1001][1001] = { };
    int x, y;
    int n = 1000; char opc;
    for(int i=0; i<d; ++i) {
        cin >> x >> y >> opc;
        mat[y][x] = opc;
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            ama[j][i].amarillos = ama[j-1][i].amarillos + (mat[j][i]=='A');
            ama[j][i].blancos = ama[j-1][i].blancos + (mat[j][i]=='B');
        }
    }
    int m;
    cin >> m;
    int N, S, W, E;
    celda ans; 
    for(int i=0; i<m; ++i) {
        cin >> N >> S >> E >> W;
        ans.amarillos = 0; ans.blancos = 0;
        for(int j=W; j<=E; ++j) {
            ans = ans + ( ama[N][j] - ama[S-1][j] );
        }
        cout << ans.amarillos << " " << ans.blancos << '\n';
    }
    return 0;   
}