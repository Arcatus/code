#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, s, r;
    cin >> p >> s >> r;
    int inc = 0;
    int d = 0;
    while( inc < p ) {
        inc += s; d++;
        if ( inc >= p ) {
            cout << d << '\n'; return 0;
        }
        inc -= r;
    }
    return 0;
}