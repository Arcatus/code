#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << n << '\n';
    srand(time(NULL));
    bool ladosOcupados[10000+1] = { };
    bool perimetros[40000+1] = { };
    bool relacion[10000+1] = { };
    bool diferencia[10000+1] = { };
    for(int i=0; i<n; ++i) {
        bool ok=true;
        while(ok) {
            int a = (rand() % 10000)+1;
            int b = (rand() % 10000)+1;
            if( ladosOcupados[a] || ladosOcupados[b] ) continue;
            if ( perimetros[2*a+2*b] ) continue;
            if ( relacion[(max(a,b)*min(a,b))%10000] ) continue;
            if ( diferencia[max(a,b) - min(a,b)] ) continue;
            cout << a << " " << b << '\n';
            ladosOcupados[a]=1;
            ladosOcupados[b]=1;
            perimetros[2*a+2*b] = 1;
            relacion[(max(a,b)*min(a,b))%10000] = 1;
            diferencia[max(a,b) - min(a,b)] = 1;
            break;        
        }
    }
    return 0;
}