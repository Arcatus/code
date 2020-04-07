#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int r=0, l=0;
    for(int i=0; i<s.size(); ++i) {
        if (s[i] == 'L') {
            l++;
        } else {
            r++;
        }
    }
    cout << r+l+1 << '\n';
    return 0;
}