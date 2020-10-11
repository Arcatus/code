#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[2*n] = { };
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    int k = 0, ans = 0, cnt;
    while(k < 2*n) {
        if(a[k] == 0){
            k++; continue;
        }
        cnt = 0;
        while(a[k] == 1) {
            cnt++; k++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}