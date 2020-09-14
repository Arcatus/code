#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    map<string, string> l1;
    cin >> n  >> m;
    string t1, t2;
    for(int i = 0; i < m; ++i) {
        cin >> t1 >> t2;
        l1.insert({t1, t2});
    }
    for(int i = 0; i < n; ++i) {
        cin >> t1;
        if(t1.size() <= l1[t1].size()) {
            cout << t1 << ' ';
        } else {
            cout << l1[t1] << ' ';        
        }
    }
    cout << '\n';
    return 0;
}