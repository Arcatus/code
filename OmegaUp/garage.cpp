#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    int peso[m];
    for(int i=0; i<m; ++i) cin >> peso[i];
    int aut;
    long long ans = 0;
    bool ocupado[n] = { };
    int libres = n;
    queue<int> cola;
    map<int,int> registro;
    for(int i=0; i<2*m; ++i) {
        cin >> aut; 
        if ( aut > 0 ) {
            if (libres > 0) {
                int idx = -1;
                for(int i=0; i<n; ++i) {
                    if( !ocupado[i] ) {
                        libres--;
                        idx = i; break;
                    }
                } 
                aut--;
                ans += (long long) peso[aut]*a[idx];
                ocupado[idx] = true;
                registro[aut] = idx;
            } else {
                cola.push(aut);
            }
        } else {
            aut = -aut;
            if ( cola.size() > 0 ) {
                int atender = cola.front();
                cola.pop();
                ans += (long long) peso[atender-1]*a[registro[aut-1]];
                registro[atender-1] = registro[aut-1];
            } else {
                ocupado[ registro[aut-1] ] = false;
                libres++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}