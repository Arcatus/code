#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int p, q;
    cin >> p >> q;
    if ( (p-2LL)*pow(p,2LL) + pow(q,4LL) < 680LL ) {
        cout << p << "\n" << q << '\n';
    }    
    return 0;
}
