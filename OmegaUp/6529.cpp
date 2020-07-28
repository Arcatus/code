#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string s;
    map<pair<char, char>, char> st;
    st.insert({make_pair('a', 'b'), 'c'});
    st.insert({make_pair('b', 'a'), 'c'});
    st.insert({make_pair('b', 'c'), 'a'});
    st.insert({make_pair('c', 'b'), 'a'});
    st.insert({make_pair('a', 'c'), 'b'});
    st.insert({make_pair('c', 'a'), 'b'});

    while(t--) {
        cin >> s;        
        int k = 0;
        int n = s.size();
        while(k < 10) {
            for(int i = 1; i < s.size() - 1; ++i) {
                if (i < s.size() - 2 && s[i] != s[i + 1] && st[{s[i], s[i + 1]}] != s[i + 2]) {
                    s[i] = st[{s[i], s[i + 1]}];
                    s = s.erase(i+1, 1);                    
                    //cout << i << " 1st " << s << ' ';
                }
                else if ( i == s.size() - 2 && s[i] != s[i + 1]) {
                    s[i] = st[{s[i], s[i + 1]}];
                    s = s.erase(i+1, 1);        
                    //cout << i << " 2nd " << s << ' ';
                }
            }
            k++;
        }
        if (s.size() > 1) {
            if (s[0] != s[1]) s.erase(0,1);
        }
        //cout << s << " " <<  s.size() << '\n';
        cout << s.size() << '\n';
    }
    
    return 0;
}
