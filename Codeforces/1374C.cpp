#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n; string s;
    while(t--) {
        cin >> n >> s;
        stack<int> p;
        vector<int> bads;
        for(int i=0; i<n; ++i) {
            if( s[i] == '(' ) {
                p.push(1);
            } else if( s[i] == ')' ) {
                if( p.empty() ) {
                    bads.push_back(-1);
                } else {
                    p.pop();
                }
            }
        }
        cout << p.size() << '\n';
    }
    return 0;
}