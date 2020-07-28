#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    string s, k, d;
    while(t--) {
        cin >> n >> s;
        int ptr1 = n - 1, ptr2 = 0;
        d = "";
        for(int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ptr1 = i; break;
            }
            d = d + s[i];
        }
        k = "";
        for(int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                ptr2 = i; break;
            }
            k = s[i] + k;
        }
        if(ptr1 < ptr2) {
            cout << d + "0" + k << '\n';
        } else {
            cout << s << '\n';
        }
    }
    return 0;
}