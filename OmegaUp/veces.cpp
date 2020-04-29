#include <bits/stdc++.h>

using namespace std;

int mem[1000000];

int convert(string s) {
    int ans = 0, inc=1;
    for(int i=s.size()-1; i>=0; i--) {
        ans += (s[i] - '0')*inc;
        inc *= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    string tmp;
    for(int i=0; i<n; i++ ) {
        if ( s[i] == '0' ) continue;
        for(int j=1; i+j-1 < n && j<=6; ++j) {
            tmp = s.substr(i,j);
            mem[ stoi(tmp,nullptr,10) ]++;
        }
    }

    int t, x;
    cin >> t;
    for(int i=0; i<t; ++i) {
        cin >> x;
        cout << mem[x] << '\n';
    }
}