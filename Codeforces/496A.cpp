#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int p;
    cin >> p;
    int l;
    int lev[n+1] = { };
    for(int i=0; i<p; ++i) {
        cin >> l;
        lev[l] = 1;
    }
    cin >> p;
    for(int i=0; i<p; ++i) {
        cin >> l;
        lev[l] = 1;
    }
    bool ok=true;
    for(int i=1; i<=n; ++i) {
        if(!lev[i]) {
            ok = false; break;
        }
    }
    if(ok) {
        cout << "I become the guy.\n";
    } else {
        cout <<"Oh, my keyboard!\n";
    }
    return 0;
}