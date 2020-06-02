#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string s;
    bool abece[255] = { };
    int cnt;
    getline(cin,s);
    while(t--) {
        getline(cin,s);
        //cerr << s << '\n';
        cnt = 0;
        for(int i=0; i<s.size(); ++i) {
            int x = tolower(s[i])-'a';
            if ( x >= 0 && x <= 26 ) {
                abece[x] = true;
            }
        }
        for(int i=0; i<26; ++i) {
            if ( abece[i] ) {
                cnt++;    
            }
            abece[i] = false;
        }
        //cerr << cnt << '\n';
        if (cnt == 26) cout << "I expel you PAZUZU\n";
        else cout << "How cute, such a prankster\n";
    }
    return 0;
}