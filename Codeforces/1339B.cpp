#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; ++i) {
            cin >> a[i];
        }
        sort(a,a+n);
        vector<int> ans;
        int p1 = 0, p2 = n-1;
        while( p1 <= p2 ) {
            ans.push_back(a[p1++]);            
            if ( p1<p2 ) ans.push_back(a[p2--]);
        }
        for(int i=ans.size()-1; i>=0; i--) {
            cout << ans[i] << ' ';
        }cout << '\n';
    }
    return 0;
}