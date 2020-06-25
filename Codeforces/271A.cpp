#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    n++;
    while(true) {
        s = to_string(n);
        int c[10] = { };
        c[s[0]-'0']++;
        c[s[1]-'0']++;
        c[s[2]-'0']++;
        c[s[3]-'0']++;
        bool ok = true;
        for(int i=0; i<10; ++i) {
            if(c[i]>1) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << n << '\n';
            break;
        }
        n++;
    }
    return 0;
}
