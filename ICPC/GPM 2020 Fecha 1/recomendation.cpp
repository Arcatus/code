#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct nodo {
    map<int, int> hijos;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    nodo a[n];
    char opc;
    int i, j;
    int maxj = 0;
    for(int i = 0; i < q; ++i) {
        cin >> opc;
        if(opc == 'R') {
            cin >> i >> j;
            if(a[i].hijos.count(j) == 0 ) {
                a[i].hijos.insert({j, 1});
            } else {
                a[i].hijos[j] += 1;
            }
        } else if(opc == 'Q') {
            cin >> i;
            if(a[i].hijos.size() == 0) {
                cout << "No info\n";
            } else {
                int indice = 0;
                int v = 0;
                bool mult = false;
                for(auto it : a[i].hijos ) {
                    if ( it.second > v ) {
                        indice = it.first;
                        v = it.second;
                        mult = false;
                    } else if(it.second == v) {
                        mult = true;
                    }
                }
                if(mult) {
                    cout << "Multiple\n";
                } else {
                    cout << indice + 1 << '\n';
                }
            }
        } else {
            
        }
    }
    return 0;
}