#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string s;
    while(t--) {
        cin >> s;
        int t = 1;
        bool ok;
        while(s.size() > 1) {
            ok  = false;
            for(int i = 0; i < s.size() - 1; i++) {
                if(s[i] != s[i + 1]) {
                    s.erase(i, 1);
                    s.erase(i, 1);
                    ok = true;
                    break;
                }
            }
            if(!ok) break;
            t++;
        }
        cout << (t & 1 ? "NET":"DA") << '\n';
    }
    return 0;
}