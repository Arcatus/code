#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    int n;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i=0; i<n;) {
        if (i < n-1 && a[i]!=b[i] && a[i]==b[i+1] && a[i+1] == b[i] ) {
            ans++;
            i+=2;
        } else {
            if (a[i] != b[i]) ans++;
            i++;
        }
    }
    cout << ans << '\n';
    return 0;
}
