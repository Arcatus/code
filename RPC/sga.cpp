#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> t;
    string s;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(t.count(s) > 0) {
            t[s]++;
        } else {
            t.insert({s, 1});
        }
    }
    vector<int> k[27];
    for(auto it = t.begin(); it != t.end(); ++it) {
        k[it->first[0] - 'A'].push_back(it->second);
    }
    ll ans = 0;
    for(int i = 0; i < 26; ++i ) {
        if(k[i].size() < 2) continue;
        ll acc[k[i].size() + 1] = { };
        acc[0] = 0;
        for(int j = 1; j <= k[i].size(); ++j) {
            acc[j] += acc[j - 1] + k[i][j - 1];
        }
        ll tmp = 0;
        for(int j = 0; j < k[i].size() - 1; ++j) {
             tmp += 2*k[i][j]*(acc[k[i].size()] - acc[j + 1]);
        }
        ans += tmp;
    }
    cout << ans << '\n';
    return 0;
}