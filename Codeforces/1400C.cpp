#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string s;
    int n, x;
    while(t--) {
        cin >> s >> x;
        int n = s.size();
        vector<char> posible[n];
        string b(n,'-');
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') {
                if(i - x >= 0) {
                    if(b[i - x] == '0') {
                        if(i + x < n) b[i + x] = '1';
                    } else {
                        b[i - x] = '1';
                    }
                } else {
                    if(i + x < n) b[i + x] = '1';
                }
            } else {
                if(i - x >= 0) b[i - x] = '0';
                if(i + x < n)  b[i + x] = '0';
            }
        }
        for(int i = 0; i < n; ++i) {
            if(b[i] == '-') {
                if((i - x >= 0 && s[i - x] == '1') || (i + x < n && s[i + x] == '1')) {
                    b[i] = '1';
                } else {
                    b[i] = '0';
                }
            }
        }
        bool ok = true;
        for(int i = 0; i < n && ok; ++i) {
            if(s[i] == '1') {
                if(i - x >= 0) {
                    if(b[i - x] == '1') continue;
                }
                if(i + x < n) {
                    if(b[i + x] == '1') continue;
                }
                ok = false;
            } else {
                if(i - x >= 0) {
                    if(b[i - x] == '1') ok = false;
                }
                if(i + x < n) {
                    if(b[i + x] == '1') ok = false;
                }
            }
        }
        if(ok) cout << b << '\n'; else cout << -1 << '\n';
    }   
    return 0;
}