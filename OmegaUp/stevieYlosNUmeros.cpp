#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, j = 2;
    ll evils[100000+5] = { };
    ll cnt = 0;
    for(ll i=1; i<=200000; ++i) {
        if (__builtin_popcount(i) % 2 == 0) {
            evils[j] = evils[j-1] + i;
            j++;
        }
    }
    while(cin >> a >> b) {
        cout << evils[b] - evils[a-1] << '\n'; 
    }    
    return 0;
}