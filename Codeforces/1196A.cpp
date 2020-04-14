#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll a[3];
    while (t--) {
        cin >>  a[0] >> a[1] >> a[2];
        sort(a,a+3);
        ll d = a[1] - a[0];
        if ( a[2] <= d ) cout << a[0] + d << '\n';
        else {
            a[2] -= d;
            a[0] += d;
            ll x = a[2]/2;
            cout << a[0] + x << '\n';
        }
    }
}