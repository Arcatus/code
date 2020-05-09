#include <bits/stdc++.h>

using namespace std;

struct nodo {
    int id, k;
    vector<int> duras;
    vector<int> suaves;
};

nodo a[1000];
bool operator <(nodo a, nodo b) {
    return a.id < b.id;
}
bool visited[1000];
bool aprobadas[1000];
bool dfs(int k) {
    for(int i=0; i<a[k].duras.size(); ++i) {
        if ( !aprobadas[ a[k].duras[i] ] ) {
            return false;
        }
    }
    visited[k] = true;
    for(int i=0; i<a[k].suaves.size(); i++ ) {
        if ( !visited[ a[k].suaves[i] ] ) {
            if ( !dfs(a[k].suaves[i]) ) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int x; string opc;
    int id, k;
    for(int i=0; i<n; ++i) {
        cin >> id >> k;
        a[i].k = k;
        a[i].id = id;
        for(int j=0; j<k; ++j) {
            cin >> opc;
            if ( opc[0] == '~' ) {
                x = stoi(opc.substr(1,opc.size()-1), nullptr, 10);
                a[i].suaves.push_back(x);
            } else {
                x = stoi(opc, nullptr, 10);
                a[i].duras.push_back(x);
            }
        }
    }
    int m;
    cin >> m;
    for(int i=0; i<m; ++i) {
        cin >> x;
        aprobadas[x] = true;
    }
    sort(a, a+n);
    for( int i=0; i<n; ++i ) {
        if ( aprobadas[i] ) continue;
        bool ans = dfs(i);
        if (ans) {
            cout << i << ' ';
        }
        fill(visited, visited+n, false);
    }cout << '\n';
    return 0;
}