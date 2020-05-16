#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, k;
    while(t--) {
        cin >> n >> k;
        vector<int> ans;
        vector<int> ans2;
        int ot = n, cnt1 = 0, cnt2 = 0;
        while(cnt1 < k-1) {
            ot-=2;
            ans.push_back(2);
            cnt1++;
        }   
        if ( ot >= 2 && ot % 2 == 0 ) {
            ans.push_back(ot); cnt1++;
        }
        while(cnt2 < k-1) {
            n-=1;
            ans2.push_back(1);
            cnt2++;
        }
        if ( n >= 1 && n % 2 == 1 ) {
            ans2.push_back(n); cnt2++;
        }
        if (cnt1 == k) {
            cout << "YES\n";
            for(int i: ans) cout << i << ' '; cout << '\n';
        } else if (cnt2 == k) {
            cout << "YES\n";
            for(int i: ans2) cout << i << ' '; cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}