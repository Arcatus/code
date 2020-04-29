#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string a; a+="W";
    cin >> a;
    vector<int> ans;
    int cnt = 0;
    for(int i=0; i<=n; ++i) {
        if ( a[i] == 'B' ) {
            cnt++;
        } else {
            if (cnt>0) {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << ans.size() << '\n';
    for(int k: ans ) {
        cout << k << ' ';
    }cout << '\n';
    return 0;
}