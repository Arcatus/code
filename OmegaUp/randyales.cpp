#include <bits/stdc++.h>

using namespace std;

string s;
unordered_map<string,int> memoria;
int solve(string s) {
    if ( memoria.count(s) > 0 ) {
        return memoria[s];
    }
    if (s.size() == 1) {
        memoria[s] = 1;
        return memoria[s];
    }
    else if (s.size() == 2) {
        memoria[s] = s[0] != s[1] ? 1 : 2;
        return memoria[s];
    }
    int ans = 1<<30; char ins;
    for(int i=0; i<s.size()-1; ++i) {
        string t = s;
        if (s[i] != s[i+1]) {
            if (s[i] == 'a' && s[i+1] == 'b' || s[i] == 'b' && s[i+1] == 'a' ) ins = 'c';
            else if (s[i] == 'b' && s[i+1] == 'c' || s[i] == 'c' && s[i+1] == 'b' ) ins = 'a';
            else if (s[i] == 'a' && s[i+1] == 'c' || s[i] == 'c' && s[i+1] == 'a' ) ins = 'b';
            t[i] = ins;
            t.erase(i+1,1);
            ans = min(ans, solve(t));
        }
    }
    memoria[s] = (ans == 1<<30) ? s.size() : ans;
    return memoria[s];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, ans = 0;
    cin >> t;
    while(t--) {
        cin >> s;
        if( s.size() == 1) {
            cout << 1 << '\n';
        } else {
            ans = solve(s);
        }
        cout << ans << '\n';
    }
    return 0;   
}