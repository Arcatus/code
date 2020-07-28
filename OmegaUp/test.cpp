#include <bits/stdc++.h>

using namespace std;

string s;
unordered_map<string,int> memoria;
map<pair<char, char>, char> st;
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
            t[i] = st[{s[i], s[i + 1]}];
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
    st.insert({make_pair('a', 'b'), 'c'});
    st.insert({make_pair('b', 'a'), 'c'});
    st.insert({make_pair('b', 'c'), 'a'});
    st.insert({make_pair('c', 'b'), 'a'});
    st.insert({make_pair('a', 'c'), 'b'});
    st.insert({make_pair('c', 'a'), 'b'});
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