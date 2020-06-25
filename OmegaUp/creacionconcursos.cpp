#include <bits/stdc++.h>

using namespace std;
int a[100000+1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        for(int i=0; i<n; ++i) cin >> a[i];
        int cnt = 1;
        int ant = a[0];
        int ans = 0;
        for(int i=1; i<n;) {
            if ( abs(a[i] - ant) <= 10 && a[i] > ant ) {
                cnt++;
                ant = a[i];
                i++;
            } else {
                ans++;
                cnt++;
                ant = ant+10;
            }
            if (cnt % 4 == 0 && i < n) {
                cnt++;
                ant = a[i];
                i++;
            }
        }
        int tmp = 4*(cnt/4 + 1) - cnt;
        if (cnt%4 != 0) ans += tmp;
        cout << ans << '\n';
    }
    return 0;
}