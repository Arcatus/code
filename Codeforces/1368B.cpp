#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k; 
    cin >> k;
    ll a[] = {1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1};
    function<ll()> check = [&]() {
        ll ans = 1;
        for(int i = 0; i < 10; ++i) ans *= a[i];
        return ans;
    };  
    int v = 0;
    while( check() < k ) {
        a[v % 10]++; v++;
    }
    string s = "codeforces";
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < a[i]; ++j) cout << s[i];
    }
    cout << '\n';
    return 0;
}