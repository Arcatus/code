#include <bits/stdc++.h>

using namespace std;

struct nodo {
    char v;
    nodo *ant, *sig;
} Z[25];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Z[0].v = 'a';
    Z[0].ant = &Z[25];
    Z[0].sig = &Z[1];
    for(int i=1; i<26-1; ++i) {
        Z[i].v = 'a'+i;
        Z[i].ant = &Z[i-1];
        Z[i].sig = &Z[i+1];
    }
    Z[25].v = 'z';
    Z[25].ant = &Z[24];
    Z[25].sig = &Z[0];
    string s; cin >> s;
    nodo *p1 = &Z[0];
    nodo *p2 = &Z[0];
    int a, b;
    int ans = 0;
    for(int i=0; i<s.size(); ++i) {
        a = 0;
        while( p1->v != s[i] ) {
            a++;
            p1 = p1->ant;
        }
        b = 0;
        while( p2->v != s[i] ) {
            b++;
            p2 = p2->sig;
        }
        ans += min(a,b);
    }   
    cout << ans << '\n';
    return 0;
}