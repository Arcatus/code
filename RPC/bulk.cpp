#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, p;
    cin >> c >> p;
    if(c == 1) cout << p << '\n';
    else {
        int descuento = 0;
        int x = p, y = c;
        c--;
        while(c--) {
            descuento += 2;
        }
        cout << x*y - descuento << '\n';
    }
    return 0;
}