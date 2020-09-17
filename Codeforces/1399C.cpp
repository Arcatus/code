#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i = 2; i <= 100; ++i) {
            int tmp = 0;
            vector<int> b = a;
            for(int j = 0; j < n; ++j) {
                if(b[j] >= i ) {
                    break;
                } else if(b[j] > 0) {
                    int d = i - b[j];
                    for(int k = 0; k < n; ++k ) {
                        if(b[k] > d) break;
                        if(b[k] == d && k != j) {
                            b[j] = 0;
                            b[k] = 0;
                            tmp++;
                            break;
                        }
                    }
                }
            }
            ans = max(ans, tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}