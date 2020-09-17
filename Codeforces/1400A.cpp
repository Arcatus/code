#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    string s;
    while(t--) {
        cin >> n >> s;
        vector<string> p;
        for(int i = 0; i < n; ++i) {
            p.push_back(s.substr(i, n));
        }
        for(int i = 0, j = 0; i < n; ++i, j++) {
            cout << p[i][j];
        }
        cout << '\n';
    }
    return 0;
}