#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n==1) { 
        cout << (s[0]=='1' ? "Yes\n":"No\n");
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        if(s[i]=='1') {
            if(i-1>=0&&s[i-1]=='1') {
                cout << "No\n";
                return 0;
            }
            if(i+1<n&&s[i+1]=='1') {
                cout << "No\n";
                return 0;
            }
        } else {
            int v=2;
            if(i-1>=0&&s[i-1]=='1') v--;
            if(i+1<n&&s[i+1]=='1') v--;
            if(v==2) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}