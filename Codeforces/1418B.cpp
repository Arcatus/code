#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        bool b[n];
        for(int i = 0; i < n; ++i) cin >> b[i];
        vector<int> p;
        for(int i = 0; i < n; ++i) {
            if(!b[i]) {
                p.push_back(a[i]);
            }
        }
        sort(p.begin(), p.end(), [](int a, int b) {
            return a > b;
        });
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(!b[i]) {
                a[i] = p[cnt++];
            }
        }
        for(int i: a) cout << i << ' '; cout << '\n';
    }
    return 0;
}