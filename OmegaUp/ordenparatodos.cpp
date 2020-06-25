<<<<<<< HEAD
#include<bits/stdc++.h> 
using namespace std; 
#define NIL 0 
#define INF INT_MAX 

class BipGraph 
{
    int m, n; 
    list<int> *adj; 
    int *pairU, *pairV, *dist; 
  
public: 
    BipGraph(int m, int n);
    void addEdge(int u, int v);
    bool bfs(); 
    bool dfs(int u);
    int hopcroftKarp();
    void printMatch(int n);
}; 

int BipGraph::hopcroftKarp() 
{ 
    pairU = new int[m+1];
    pairV = new int[n+1];
    dist = new int[m+1];

    for (int u=0; u<=m; u++) 
        pairU[u] = NIL; 
    for (int v=0; v<=n; v++) 
        pairV[v] = NIL; 

    int result = 0; 
    while (bfs()) { 
        for (int u=1; u<=m; u++) {
            if (pairU[u]==NIL && dfs(u)) result++;
        }
    }
    return result; 
} 
bool BipGraph::bfs() 
{ 
    queue<int> Q;
    for (int u=1; u<=m; u++) {
        if (pairU[u]==NIL) { 
            dist[u] = 0; 
            Q.push(u); 
        } 
        else dist[u] = INF;
    }     
    dist[NIL] = INF;
    while (!Q.empty()) {         
        int u = Q.front();
        Q.pop();

        if (dist[u] < dist[NIL]) {
            for (auto i=adj[u].begin(); i!=adj[u].end(); ++i) {
                int v = *i;
                if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    cerr << (dist[NIL] != INF) << '\n';
    return (dist[NIL] != INF);
} 

bool BipGraph::dfs(int u) 
{ 
    if (u != NIL) { 
        list<int>::iterator i; 
        for (i=adj[u].begin(); i!=adj[u].end(); ++i) { 
            int v = *i; 
            if (dist[pairV[v]] == dist[u]+1) { 
                if (dfs(pairV[v]) == true) { 
                    pairV[v] = u; 
                    pairU[u] = v; 
                    return true; 
                } 
            } 
        }         
        dist[u] = INF; 
        return false; 
    } 
    return true; 
} 

BipGraph::BipGraph(int m, int n) 
{ 
    this->m = m; 
    this->n = n; 
    adj = new list<int>[m+1]; 
} 

void BipGraph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v);
} 

void BipGraph::printMatch(int n) {
    for(int i=1; i<=n; ++i) {
        cout << this->pairV[i] - 1 << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, x;
    cin >> n >> a >> b;
    vector<pair<int,int>> vv[n+1];
    for(int i=0; i<a; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> x;            
            vv[x].push_back({max(0,j-b), min(n-1,j+b)});
        }
    }
    vector<pair<int,int>> validos(n);
    for(int i=0; i<n; ++i) {
        pair<int, int> tmp = vv[i][0];
        for(int j=1; j<vv[i].size(); ++j) {
            if ( min(vv[i][j].second, tmp.second) >= max(vv[i][j].first, tmp.first) ) {
                tmp = { max(vv[i][j].first, tmp.first) , min(vv[i][j].second, tmp.second) };
            } else {
                cout << -1 << '\n';
                return 0;
            }
        }
        validos[i] = tmp;
    }
    BipGraph g(n, n);
    for(int i=0; i<n; ++i) {
        auto k = validos[i];        
        for(int j=k.first; j <= k.second; ++j) {
            g.addEdge(i+1, j+1);
        }
    }
    int res = g.hopcroftKarp();
    if (res == n) {
        g.printMatch(n);
    } else {
        cout << -1 << '\n';
=======
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
>>>>>>> 91348413c0cc0ca2c9e5c245fd09ffa3f89ba80d
    }
    return 0;
}