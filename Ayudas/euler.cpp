#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double lo, hi, inc;
    cin >> lo >> hi >> inc;
    
    
    cout.precision(20);
    cout << fixed;
    char rn[64];
    for(; lo <= hi; lo+=inc) {
        cout << lo << '\n';
        sprintf(rn, "%.4lf\n", lo);
        lo = atof(rn);
    }    
    return 0;
}