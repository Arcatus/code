#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    s += s;
    int f[s.size()], i;
    memset(f, -1, sizeof f);
    int k = 0; char sj;
    for(int j=1; j<s.size(); ++j) {
        sj = s[j];
        i = f[j-k-1];
        while (i != -1 && sj != s[k + i + 1]) {
            if (sj < s[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if ( sj != s[k + i + 1] ) {
            if ( sj < s[k] ) {
                k = j;
            }
            f[j - k] = -1;
        } else
            f[j - k] = i + 1;
    }
    cout << k << '\n';
}