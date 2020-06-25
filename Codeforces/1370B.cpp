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
        vector<int> pares;
        vector<int> impares;
        for(int i=0; i<2*n; ++i) {
            cin >> x;
            if (x&1) {
                impares.push_back(i);
            } else {
                pares.push_back(i);
            }
        }
        vector<pair<int,int>> ans;
        for(int i=0; i+1<impares.size(); i+=2) {
            ans.push_back({impares[i], impares[i+1]});
        }
        for(int i=0; i+1<pares.size(); i+=2) {
            ans.push_back({pares[i], pares[i+1]});
        }
        for(int i=0; i<n-1; ++i) {
            cout << ans[i].first+1 << " " << ans[i].second+1 << '\n';
        }
    }
    return 0;
}