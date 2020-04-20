#include <bits/stdc++.h>

using namespace std;
int n, c;
vector<vector<int>> bit(2, vector<int>(1e5+1));

void upbit(int idx, int v, int bt) {
    while(idx <= n) {
        bit[bt][idx] += v;
        idx += idx&-idx;
    }
}

int qbit(int idx, int bt) {
    int ans = 0;
    while( idx > 0) {
        ans += bit[bt][idx];
        idx -= idx&-idx;
    }
    return ans;
}

int qrs(int x) {
    return qbit(x,0)*x - qbit(x,1);
}

void ur(int a, int b, int v) {
    upbit(a, v, 0);
    upbit(b+1,-v, 0);
    upbit(a,(a-1)*v, 1);
    upbit(b+1, -v*b, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, v;
    cin >> n >> c;
    char opc;
    for(int i=0; i<c; ++i) {
        cin >> opc;
        if (opc=='P') {
            cin >> v; v++;
            int ans = qrs(v) - qrs(v-1);
            cout << ans << '\n';
        } else {
            cin >> a >> b;
            a++, b++;
            ur(a, b-1, 1);
        }
    }
    return 0;
}