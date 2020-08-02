#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    map<pair<char, char>, char> st;
    st.insert({make_pair('a', 'b'), 'c'});
    st.insert({make_pair('b', 'a'), 'c'});
    st.insert({make_pair('b', 'c'), 'a'});
    st.insert({make_pair('c', 'b'), 'a'});
    st.insert({make_pair('a', 'c'), 'b'});
    st.insert({make_pair('c', 'a'), 'b'});
    while(true) {
        int n = s.size();
        if ( n > 3) {
            for(int i = 1; i < n - 2; ++i ) {
                char op = st[{s[i], s[i + 1]}];
                if ( s[i - 1] != op && s[i + 2] != op ) {
                    s[i] = op;
                    s.erase(i + 1, 1);
                    break;
                }
            }
        } else {
            char op = st[{s[0], s[i + 1]}];
        }
    }
    return 0;
}