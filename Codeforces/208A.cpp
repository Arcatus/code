#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    while(s.find("WUB") != string::npos) {
        s.replace(s.find("WUB"), 3, " ");
    }
    int k = 0;
    while(s.size() > 0 && s[0] == ' ') {
        s.erase(s.begin());
    }
    cout << s << '\n';
    return 0;
}