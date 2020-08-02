#include <bits/stdc++.h>

using namespace std;

struct player {
    int x, y;
};

struct nodo {
    int v, c;
};

bool operator <(nodo a, nodo b) {
    return a.c < b.c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    player a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    player b[n];
    for(int i = 0; i < n; ++i) {
        cin >> b[i].x >> b[i].y;
    }
    vector<int> adj[n];
    function<bool(int x1, int y1, int x2, int y2, int x, int y)> 
        PuntoSobreRecta = [](int x1, int y1, int x2, int y2, int x, int y) {
            if (x2 == x1) {
                return (x1 == x) ? true: false;
            }
            double pendiente = (double) (y2 - y1) / (x2 - x1);
            double ans = (double) abs( (y - y1) - pendiente*(x - x1) );
            return (ans < 1e-9);
    };
    function<bool(int x1, int y1, int x2, int y2, int x, int y)>
        dentroLimites = [](int x1, int y1, int x2, int y2, int x, int y) {
            int lox = min(x1, x2), hix = max(x1, x2);
            int loy = min(y1, y2), hiy = max(y1, y2);
            return (lox <= x && x <= hix && loy <= y && y <= hiy);
    };
    /*
    if ( dentroLimites(1,1,1,4,1,2) ) {
        cerr << "dentro limites\n";
    }
    if (PuntoSobreRecta(1,1,1,4,1,2)) {
        cerr << "sobre recta\n";
    }
    return 0;
    */
    bool mat[n][n] = { };
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j ) {
            if( !mat[i][j] && i != j) {
                bool ok = true;
                for(int k = 0; k < n; ++k) {
                    if ( dentroLimites(a[i].x, a[i].y, a[j].x, a[j].y, b[k].x, b[k].y)
                             && PuntoSobreRecta(a[i].x, a[i].y, a[j].x, a[j].y, b[k].x, b[k].y)) {
                        ok = false; break;
                    }
                }
                for(int k = 0; k < n && ok; ++k) {
                    if (k != i && k != j)
                        if (dentroLimites(a[i].x, a[i].y, a[j].x, a[j].y, a[k].x, a[k].y)
                                && PuntoSobreRecta(a[i].x, a[i].y, a[j].x, a[j].y, a[k].x, a[k].y)) {
                            ok = false; break;
                        }
                }
                if(ok) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    mat[i][j] = mat[j][i] = true;
                    //cerr << "conection " << i << " " << j << '\n';
                }
            }
        }
    }
    priority_queue<nodo> q;
    q.push(nodo{0, 0});
    int distancia[n];
    fill(distancia, distancia + n, -1);
    while(!q.empty()) {
        nodo p = q.top();
        q.pop();
        if (distancia[p.v] == -1) {
            distancia[p.v] = p.c;
            for(int i = 0; i < adj[p.v].size(); ++i ) {
                q.push(nodo{ adj[p.v][i], p.c + 1 });
            }
        }
    }
    cout << distancia[n - 1] << '\n';
    return 0;
}