#include <bits/stdc++.h>

using namespace std;

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
        string s = "";
        int k = 51;
        for(int i = 0; i < k; ++i) s += "a";
        string t = "";
        cout << s.substr(0, k) << '\n';
        for(int i = 0; i < n; ++i) {
            t = s.substr(0, a[i]);
            for(int j = a[i]; j < k; ++j) {
                t += (s[j] == 'a' ? 'b' : 'a');
            }
            s = t;
            cout << s.substr(0, k) << '\n';
        }
    }
    return 0;
}