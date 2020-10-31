#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, n;
    cin >> a >> b >> n;
    int turno = 1;
    while(n) {
        if(turno&1) {
            n -= __gcd(n, a);
        } else {    
            n -= __gcd(n, b);
        }
        turno++;
    }
    cout << (turno & 1) << '\n';
    return 0;
}