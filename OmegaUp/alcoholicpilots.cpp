#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll v1, d1, v2, d2;
    int cnt = 1;
    while(cin >> v1 >> d1 >> v2 >> d2) {
        if(v1==0&&v2==0&&d1==0&&d2==0) break;
        if ( d1*v2 < d2*v1 ) {
            cout << "Case #"<< cnt++ <<": You owe me a beer!\n";
        } else {
            cout << "Case #"<< cnt++ <<": No beer for the captain.\n";
        }
        ll num = v1*d2 + v2*d1;
        ll den = 2*v1*v2;
        ll d = __gcd(num,den);
        num = num / d;
        den = den / d;
        cout << "Avg. arrival time: ";
        if ( num % den == 0 ) {
            cout << num/den << '\n';
        } else {
            cout << num << "/" << den << '\n';
        }
    }
    return 0;
}