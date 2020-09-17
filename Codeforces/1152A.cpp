#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt1 = 0, cnt2 = 0, x;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(x&1)cnt1++;
        else cnt2++;
    }
    int cnt3 = 0, cnt4 = 0;
    for(int i = 0; i < m; ++i) {
        cin >> x;
        if(x&1)cnt3++;
        else cnt4++;
    }
    cout << min(cnt1, cnt4) + min(cnt2, cnt3) << '\n';
    return 0;
}