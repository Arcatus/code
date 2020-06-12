#include <bits/stdc++.h>

using namespace std;

struct matryoshkas {
    int tamanio;
    int precio;
}
bool operator<( matryoshkas a, matryoshkas b ) {
    if (a.precio == b.precio) {
        return a.tamanio < b.tamanio;
    } else {
        return a.precio < b.precio;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    matryoshkas a[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i].tamanio >> a[i].precio;
    }
    return 0;
}