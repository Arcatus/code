#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int k = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '7' || s[i] == '4') {
            k++;
        }
    }
    if(k == 0) {
        cout << "NO\n";
        return 0;
    }
    while (k) {
        int p = k % 10;
        if (p == 7 || p == 4) {
            k /= 10;
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}