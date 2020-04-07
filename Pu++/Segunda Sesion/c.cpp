#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    int lo = 0, hi = n-1;
    int sere = 0, dima = 0, t = 0;
    while( lo <= hi ) {
        if( a[lo] > a[hi] ) {
            if ( t%2==0 ) sere += a[lo];
            else dima += a[lo];
            lo++;
        } else {
            if ( t%2==0 ) sere += a[hi];
            else dima += a[hi];
            hi--;
        } t++;
    }
    cout << sere << " " << dima << '\n';
    return 0;
}