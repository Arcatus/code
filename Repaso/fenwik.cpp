#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, a[100], bit[100];

void add(int p, int x) {
    for(int i = p; i <= n; i += (i & -i) ) {
        bit[i] += x;
    }
}
int query(int x) {
    int ans = 0;
    for(int i = x; i > 0; i -= (i & -i)) {
        ans += bit[i];
    }
    return ans;
}
int query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    n = 10;
    for(int i = 1; i <= 10; ++i) {
        add(i, i);
    }
    cout << query(3, 5) << '\n';

    return 0;
}