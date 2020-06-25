#include <bits/stdc++.h>

using namespace std;

int num(int k) {
    if (k < 1) return 1;
    else if (k < 2) return 2;
    else if (k < 5) return 3;
    else if (k < 8) return 4;
    else return 5;
}

int nnum(int k) {
    if (k < 1) return 1;
    else if (k < 8) return 2;
    else return 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    if ( n == 1 ) {
        cout << nnum(s[0]-'0') << '\n';
    } else {
        int p1 = 0, p2 = n-1;
        int ans = 1;
        int cnt[n];
        cnt[0] = num(s[0]-'0');
        for(int i=1; i<n; ++i) {
            cnt[i] = 5;
            
        }
        cout << ans << '\n';
    }
    return 0;
}