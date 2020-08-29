#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, s;
    cin >> m >> s;
    if(m == 1 && s == 0) {
        cout << 0 << " " << 0 << '\n';
        return 0;
    }
    string k = string(m, '0');
    int p = 0;
    while(p < m) {
        if(s >= 10) {
            int t = s - 9;
            s -= 9;
            k[p] = '9';
        } else {
            int t = s;
            k[p] = '0' + t;
            s = 0;
        }
        p++;
    }
    if (s == 0) {
        string o = k;
        reverse(o.begin(), o.end());
        if(o[0] == '0') {
            for(int i = 0; i < o.size(); ++i) {
                if(o[i] != '0') {
                    o[0] = '1';
                    o[i] = o[i] - 1;
                    break;
                }
            }
            if (o[0] == '0') {
                cout << -1 << " " << -1 << '\n';
            } else {
                cout << o << " " << k << '\n';
            }
        } else {
            cout << o << " " << k << '\n';
        }
    } else {
        cout << -1 << " " << -1 << '\n';
    }
    return 0;
}