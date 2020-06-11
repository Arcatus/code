#include <bits/stdc++.h>

using namespace std;

struct madriguera{
    string nombre;
    int posicion;
};

struct raton {
    string nombre;
    int posicion;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int r;
    cin >> r;
    raton a[r];
    for(int i=0; i<r; ++i) {
        cin >> a[i].nombre >> a[i].posicion;
    }
    int h;
    cin >> h;
    madriguera b[h];
    for(int i=0; i<h; ++i) {
        cin >> b[i].nombre >> b[i].posicion;
    }
    sort(a, a+r,[](raton a, raton b) {
        return a.posicion < b.posicion;
    });
    sort(b, b+h,[](madriguera a, madriguera b) {
        return a.posicion < b.posicion;
    });    
    for(int i=0; i<r; ++i) {
        cout << a[i].nombre << " " << b[i].nombre << '\n'; 
    }
    return 0;
}