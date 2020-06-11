#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long int;

ll binaryExp(ll a, ll b, ll m) {
    ll ans = 1LL;
    a%=m;
    while(b) {
        if(b&1) {
            ans = ((ans%m)*(a%m))%m;
        }
        a=(a*a)%m;
        b/=2;
    }
    return ans%m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x, y, z, ans;
    cin >> x >> y >> z;
    ans = binaryExp(x,y,z);
    cout << ans << '\n';
    return 0;
}