#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    int len =(int)ceil(sqrt(n));
    vector<vector<int>> b(len);
    for(int i=0; i<n; ++i) {
        b[i/len].push_back(a[i]);
    }
    for(int i=0; i<len; ++i) {
        sort(b[i].begin(), b[i].end());
    }    
    int m, ans;
    cin >> m;
    int i, f, v;
    for(int j=0; j<m; ++j) {
        cin >> i >> f >> v;
        int l = i/len, r = f/len;
        ans = 0;
        if (i == f) {
            for(int x=l; x<=r; ++x ) {
                if( a[x] <= v ) {
                    ans++;
                } else break;
            }
            cout << ans << '\n';
        } else {
            for (int x=i, end=(l+1)*len-1; x<=end; ++x){
                
            }
            for (int x=l+1; x<=r-1; ++x) {

            }
            for (int x=r*len; x<=f; ++x) {

            }
        }
    }
    return 0;
}