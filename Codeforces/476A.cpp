#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int ans =  -1;
    for(int i = n/2 + (n % 2); i <= n; ++i) {
        if(i % m == 0) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}