#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ind(10);
bool dp[10][1000000+1] = { };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int cuenta[10];
    for(int i=0; i<n; ++i) {
        dp[ s[i]-'0' ][i] = true;
        ind[s[i]-'0'].push_back(i);
    }
    int t;
    cin >> t;
    string p;
    while(t--){
        cin >> p;
        int ans = 0;
        for(int i : ind[p[0]-'0']) {
            bool success = true;
            for(int j=0; j<p.size()-1; ++j) {
                if ( dp[p[j]-'0'][i+j] && dp[p[j+1]-'0'][i+j+1] && i+j+1 < n ) {
                    continue;
                } else {
                    success = false; break;
                }
            }
            if (success) ans++;
        }
        cout << ans << '\n';
    }
}