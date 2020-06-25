#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    if( s.compare(t) == 0 ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}