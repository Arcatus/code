#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    int level = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i]=='D') {
            if(level==0)cnt++;
            level-=1;
        } else {
            level+=1;
        }
    }
    cout << cnt << '\n';
    return 0;
}