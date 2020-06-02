#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline bool isInside(const ll& circle_x,const ll& circle_y,const ll& rad,const ll& x,const ll& y) {
    if ( sqrt(pow(x-circle_x,2) + pow(y-circle_y,2)) <= rad ) return true;
    else return false;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll xc, yc, xm, ym;
    cin >> xc >> yc >> xm >> ym;
    ll armas[255];
    char opc;
    ll rad;
    for(int i=0; i<n; ++i) {
        cin >> opc >> rad;
        armas[opc] = rad;
    }
    ll r, xr, yr, distanceCh, distanceMed;
    int victorias = 0;
    for(int i=0; i<m; ++i) {
        cin >> opc >> xr >> yr;
        r = armas[opc];
        if ( isInside(xr, yr, r, xc, yc) ) {
            if ( victorias == 0 ) {
                if ( isInside(xr,yr,r,xm,ym) ) {
                    cout << "Ethan dira: Au au, no puedo ganar, amo\n";
                } else {
                    cout << "El futuro esta condenado\n";
                }
            } else {
                if ( victorias == 1 ) {
                    cout << "Chimpa gana!\n";
                } else if ( victorias > 1 ) {
                    cout << "Chimpa gana x " << victorias << "!\n";
                }
            }
            return 0;
        }
        else if ( isInside(xr,yr,r,xm,ym) ) {
            victorias++;
        }
    }
    if ( victorias == 0 ) {
        cout << "El futuro esta condenado\n";
    }
    else if ( victorias == 1 ) {
        cout << "Chimpa gana!\n";
    } else if ( victorias > 1 ) {
        cout << "Chimpa gana x " << victorias << "!\n";
    }
    return 0;
}