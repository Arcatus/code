#include <bits/stdc++.h>

using namespace std;

int a[100000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    bool ok;
    int lo = 1, hi = 1000000000;
    int cnt = 0;
    int oldmid;
    while( lo < hi ) {
        int mid = (hi+lo)/2;
        if (mid == oldmid) break;
        int j = 0, k = 1, i;
        ok = true;
        for(i=0; i<p-1; ++i) {
            while( k < n && (a[k] - a[j]) < mid) {
                k++;
            }
            if ( k == n && (a[k] - a[j]) < mid ) {
                ok = false;
                break;
            }
            j = k;
        }
        if(ok) {
            lo = mid;
        } else {            
            hi = mid;
        }
        oldmid = mid;
    }
    cout << lo << '\n';
    return 0;
}