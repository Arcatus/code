#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int cnt = 1, cnt_old = 0;
    char active = s[0];
    for(int i=1; i<s.size(); ++i) {
        if ( active == s[i] ) {
            cnt++;
        } else {
            if ( cnt > cnt_old ) {
                cnt_old = cnt;
            }
            cnt = 1;
            active = s[i];        
        }
    }
    cout << max(cnt, cnt_old) << '\n';
    return 0;
}