#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll n, int p) {
    ll mask = 0LL, k;
    ll opa, opb, opc, opd, ope;
    bool fir = n & 1;
    bool sec = n & 2;
    bool th  = n & 4;
    bool fo  = n & 8; 
    bool fi  = n & 16;
    if (fir) n |= (1LL << p);
    if (sec) n |= (1LL << (p + 1));
    if (th)  n |= (1LL << (p + 2));
    if (fo)  n |= (1LL << (p + 3));
    if (fi)  n |= (1LL << (p + 4));
    for(int i = 0; i < p; ++i) {
         opa = (((n & (1LL << i))) > 0) << 0;
         opb = (((n & (1LL << (i + 1)))) > 0) << 1;
         opc = (((n & (1LL << (i + 2)))) > 0) << 2;
         opd = (((n & (1LL << (i + 3)))) > 0) << 3;
         ope = (((n & (1LL << (i + 4)))) > 0) << 4;
         k = opa + opb + opc + opd + ope;
         //cerr << k << '\n';
         mask |= (1LL << k);
    }
    return mask;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);   
    int t;
    cin >> t;
    ll mask_max = 0LL;
    for(int i = 0; i < 32; ++i) {
        mask_max |= (1LL << i);
    }
    ll n;
    while(t--) {
        cin >> n;
        ll m = solve(n, 32);
        //cerr << m << '\n';
        if( m == mask_max ) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
