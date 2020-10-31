#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<string> vals;
    for(int i = 1; i <= 9; ++i) {
        string t = to_string(i);
        for(int j = 0; j < 4; ++j) {
            vals.push_back(t);
            t += to_string(i);
        }
    }
    /*
    for(string r: vals) {
        cerr << r << ' ';
    }
    cerr << '\n';
    */
    string x;
    while(t--) {
        cin >> x;
        int ans = 0;
        for(string r: vals) {
            if(r == x) {
                ans += r.size();
                break;
            } else {
                ans += r.size();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}