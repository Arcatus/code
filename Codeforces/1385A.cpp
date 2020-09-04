#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y, z;
    int t;
    cin >> t;
    while(t--) {
        cin >> x >> y >> z;
        int pa = min(x, y);
        int pb = min(x, z);
        int pc = min(y, z);
        if(x == max(pa, pb) && y == max(pa, pc) && z == max(pb, pc)) {
            cout << "YES\n";
            cout << pa << " " << pb << " " << pc << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}