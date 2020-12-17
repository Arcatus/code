#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[18];
    for(int i = 0; i < 18; ++i) cin >> a[i];
    string tmp;
    int ans = 0;
    getline(cin, tmp);
    for(int i = 0; i < 18; ++i ) {
        getline(cin, tmp);
        if(tmp.compare("hole in one") == 0) {
            ans += 1;
        } else if(tmp.compare("condor") == 0) {
            ans += a[i] - 4;
        } else if(tmp.compare("albatross") == 0) {
            ans += a[i] - 3;
        } else if(tmp.compare("eagle") == 0) {
            ans += a[i] - 2;
        } else if(tmp.compare("birdie") == 0) {
            ans += a[i] - 1;
        } else if(tmp.compare("par") == 0) {
            ans += a[i];
        } else if(tmp.compare("bogey") == 0) {
            ans += a[i] + 1;
        } else if(tmp.compare("double bogey") == 0) {
            ans += a[i] + 2;
        } else if(tmp.compare("triple bogey") == 0) {
            ans += a[i] + 3;
        } 
    }
    cout << ans << '\n';
    return 0;
}