#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, v;
    cin >> n >> k;
    multiset<ll> st;
    for(int i = 0; i < n; ++i) {
        cin >> v;
        st.insert(v);
    }
    int ans = 0;
    while(!st.empty()) {
        ll x = *st.begin();
        st.erase(st.begin());
        if(x>=k) {
            cout << ans << '\n';
            return 0;
        }
        if(st.empty()) {
            cout << -1 << '\n';
            return 0;
        }
        ll y = *st.begin();
        st.erase(st.begin());
        st.insert(x+2*y);
        ans++;
    }
    return 0; 
}