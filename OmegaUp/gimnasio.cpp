#include <bits/stdc++.h>

using namespace std;

struct maquina {
    int tiempo;
    int enfriamiento;
} M[20];

struct vecinos {
    int u, r, t;
} N[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0; i<10; ++i) {
        cin >> M[i].tiempo >> M[i].enfriamiento;
    }
    int u, r, t;
    for(int i=0; i<10; ++i) {
        cin >> N[i].u >> N[i].r >> N[i].t;
    }
    int t = 0;
    int maq[10] = { };
    while( maq[3] != 3 ) {
        if (  )
    }
    
    return 0;
}