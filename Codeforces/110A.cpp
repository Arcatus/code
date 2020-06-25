#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int cnt=0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == '7' || s[i] == '4') {
            cnt++;
        } 
    }
    s = to_string(cnt);
    for(int i=0; i<s.size(); ++i) {
        if ( s[i] == '7' || s[i] == '4' ) {

        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}