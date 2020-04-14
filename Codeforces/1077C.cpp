#include <bits/stdc++.h>

using namespace std;

struct dato { 
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    dato a[n];
    long long sum = 0;
    for(int i=0; i<n; ++i) {
        cin >> a[i].x;
        sum += a[i].x;
        a[i].y = i+1;
    }
    sort(a,a+n, [](dato a, dato b){
        return a.x < b.x;
    });
    long long s = sum;
    s -= a[n-1].x;
    vector<long long> ans;
    if( s - a[n-2].x == a[n-2].x ) {
        ans.push_back(a[n-1].y);
    }
    long long m = a[n-1].x;
    for(long long i=n-2; i>=0; i--) {
        if( sum - a[i].x == 2*m ) {
            ans.push_back(a[i].y);
        }   
    }
    cout << ans.size() << '\n';
    for(long long i=0; i<ans.size(); ++i) {
        cout << ans[i] << ' ';
    }cout << '\n';
    return 0;
}