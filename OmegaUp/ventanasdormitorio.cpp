#include <bits/stdc++.h>

using namespace std;

struct ventana {
    int l, r;
};

bool operator <(ventana a, ventana b) {
    return a.l < b.l;
}
bool operator ==(ventana a, ventana b) {
    return a.l == b.l && a.r == b.r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ventana a[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i].l >> a[i].r;
    }
    sort(a, a+n);
    int m;
    cin >> m; char q; int x; bool ok;
    bool abierto[n] = { };
    for(int i=0; i<n; ++i) abierto[i] = 1;
    for(int i=0; i<m; ++i) {
        cin >> q >> x;
        int lo = 0, hi = n-1;
        ok = 1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if ( a[mid].l <= x && x <= a[mid].r ) {
                if ( q == 'P') {
                    if (abierto[mid]) ok = 0;
                    break;
                } else {
                    abierto[mid] = !abierto[mid];
                }
            }
            if ( x < a[mid].l ) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        if(q=='P') cout << ok << '\n';
    }
    return 0;
}