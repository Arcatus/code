#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli n, c;
vector<vector<lli>> bit(2, vector<lli>(1e6+1));

void upbit(lli idx, lli v, lli bt) {
    while(idx <= n) {
        bit[bt][idx] += v;
        idx += idx&-idx;
    }
}

lli qbit(lli idx, lli bt) {
    lli ans = 0;
    while( idx > 0) {
        ans += bit[bt][idx];
        idx -= idx&-idx;
    }
    return ans;
}

lli qrs(lli x) {
    return qbit(x,0)*x - qbit(x,1);
}

void ur(lli a, lli b, lli v) {
    upbit(a, v, 0);
    upbit(b+1,-v, 0);
    upbit(a,(a-1)*v, 1);
    upbit(b+1, -v*b, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli t;
    cin >> t;
    lli opc, a, b, v;
    while(t--) {
        cin >> n >> c;
        for(lli i=0; i<c; ++i) {
            cin >> opc >> a >> b;
            if (opc) {
                lli ans = qrs(b) - qrs(a-1);
                cout << ans << '\n';
            } else {
                cin >> v;
                ur(a, b, v);
            }
        }
        for(int i=0; i<=1000000; ++i) {
            bit[0][i]=0;
            bit[1][i]=0;
        }
    }
    return 0;
}