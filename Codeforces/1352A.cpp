#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, x;
    while(t--) {
        cin >> n;
        vector<int> ans;
        int k = 1;
        while (n) {
            x = n % 10;
            if (x != 0) ans.push_back(x*k);
            n = n/10; k*=10;
        }
        cout << ans.size() << '\n';
        for(int i: ans) cout << i << ' '; cout << '\n';
    }
    return 0;
}