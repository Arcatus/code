#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> st;
    int x;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        st.insert(x);
    }
    multiset<int> st2 = st;
    int b[n - 1];
    for(int i = 0; i < n - 1; ++i) {
        cin >> b[i];
        st.erase(st.lower_bound(b[i]));
    }
    int v1 = *st.begin();
    st2.erase(st2.lower_bound(v1));
    int c[n - 2];
    for(int i = 0; i < n - 2; ++i) {
        cin >> c[i];
        st2.erase(st2.lower_bound(c[i]));
    }
    int v2 = *st2.begin();
    cout << v1 << "\n" << v2 << "\n";
    return 0;
}