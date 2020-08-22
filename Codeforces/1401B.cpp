#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll ceros1, unos1, dos1;
    ll ceros2, unos2, dos2;
    while(t--) {
        cin >> ceros1 >> unos1 >> dos1;
        cin >> ceros2 >> unos2 >> dos2;
        ll ans = 0;
        ll tmp = min(dos1, unos2);
        ans += 2*tmp;
        dos1 -= tmp;
        unos2 -= tmp;
        //me sobraron 2
        tmp = dos1;
        dos2 -= tmp;
        dos1 -= tmp;
        tmp = min(ceros1, dos2);
        ceros1 -= tmp;
        dos2 -= tmp;
        cout << ans - 2*min(unos1, dos2)  << '\n';
    }
    return 0;
}