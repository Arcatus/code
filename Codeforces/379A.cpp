#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int tot = a;
    int ans = 0;
    int consumidas = 0;
    while(tot > 0) {
        ans++;
        consumidas++;
        tot--;
        if(consumidas == b) {
            tot++;
            consumidas = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}