#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll k = 5;
    string ans[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    if(n < 6) {
        cout << ans[n - 1] << '\n';
    } else {
        ll inc = 2*k, tmp, div = 2;
        while(k + inc < n) {
            tmp = inc*2;
            k = k + inc;
            inc = tmp;
            div*=2;
        }
        n -= k;
        ll bkt = 0;
        ll cnt = 0;
        for(ll i = 1; i <= n; ++i) {
            cnt++;
            if(i == n) break;
            if(cnt == div) {
                bkt++;
                cnt = 0;
            }
        }
        cout << ans[bkt] << '\n';
    }
    return 0;
}