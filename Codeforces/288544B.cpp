#include <bits/stdc++.h>

using namespace std;

struct carta {
    int ai, bi;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    carta a[n];
    for(int i = 0; i < n; ++i) cin >> a[i].ai >> a[i].bi;
    sort(a, a + n, [](carta a, carta b) {
        if(a.bi == b.bi) {
            return a.ai > b.ai;
        } else {
            return a.bi > b.bi;
        }
    });
    int k = 1;
    int t = a[0].bi;
    int ans = a[0].ai;
    while(k < n && t > 0) {
        t--;
        ans += a[k].ai;
        t += a[k].bi;
        k++;
    }
    cout << ans << '\n';
    return 0;
}