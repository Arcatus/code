#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, a, b;
    while(t--){
        cin >> n >> a >> b;
        char s[n+5];
        int lo = 0, of = -1;
        for(int i=0; i<a; ++i) {
            if ( b > 0 ) of++; b--;
            s[i] = 'a' + of;
        }
        for(int i=a; i<n; ++i) {
            s[i] = s[lo++];
        }
        s[n]=0;
        cout << s << '\n';
    }
    return 0;
}