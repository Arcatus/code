#include <bits/stdc++.h>

using namespace std;

int n;
int bit[100000+1];

void update(int k, int v) {
    while( k <= n ) {
        bit[k] += v;
        k += (k&-k);
    }
}

int getVal(int k) {
    int ans = bit[k];
    if ( k > 0 ) {
        int z = k - (k&-k); k--;
        while( z != k ) {
            ans -= bit[k];
            k-=(k&-k);
        }
    }
    return ans;
}

int query(int k) {
    int ans = 0;
    while(k > 0) {
        ans += bit[k];
        k-=(k&-k);
    }
    return ans;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int x;
    for(int i=1; i<=n; ++i) {
        cin >> x;
        update(i, x);
    }
    int m, a, b;
    cin >> m;
    char opc;
    for(int i=0; i<m; ++i) {
        cin >> opc;
        if ( opc == 'P' ) {
            cin >> a >> b;
            cout << query(b) - query(a) << '\n';
        } else {
            cin >> a >> b;
            update(a+1,- getVal(a+1) + b);
        }
    }
    return 0;
}