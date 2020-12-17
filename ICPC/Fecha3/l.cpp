#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

bool zAlgorithm(string pattern, string target)
{
    string s = pattern+"$"+target;
    int n = s.size();
    int k = pattern.size();
    int z[n] = { };
    int l = 0, r = 0;
    for(int i=1; i< n; ++i) {
        if ( i > r ) {
            l = i, r = i;
            while( r < n && s[r-l] == s[r] ) r++;
            z[i] = r - l; r--;
        } else {
            int k = i - l;
            if ( z[k] < r - i + 1 ) {
                z[i] = z[k];
            } else {
                l = i;
                while( r < n && s[r-l] == s[r] ) r++;
                z[i] = r - l; r--;
            }
        }
    }
    for(int i = 1; i < n; ++i) {
        if(z[i]==k) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n;
    string s, tmp;
    set<string> st;
    cin >> s;
    tmp=s+s;
    st.insert(tmp);
    bool ok;
    for(int i = 1; i < n; ++i) {
        ok = true;
        cin >> s;        
        r = s.size()*2;
        for(auto it=st.begin(); it!=st.end(); ++it) {
            if(r != (*it).size()) continue;
            if(zAlgorithm(s, *it)) {
                ok = false; break;
            }
        }
        if(ok) {
            tmp=s+s;
            st.insert(tmp);
        }
    }
    cout << st.size() << '\n';
    return 0;
}