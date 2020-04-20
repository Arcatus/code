#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        int a = s.find_first_of("1");
        int b = s.find_last_of("1");
        int ans = 0;
        if ( a!=b ) {
            for(int i=a+1; i<=b-1; ++i) {
                if ( s[i] == '0' ) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}