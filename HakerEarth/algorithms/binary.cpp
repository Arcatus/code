#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
#include <map>

typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q, x;
    cin >> n;
    int f[n];
    for(int i=0; i<n; ++i) cin >> f[i];
    sort(f,f+n);
    auto mybin = [&](int a, int b, int x)
    {
        int l=a, r=b-1, m;
        while( l <= r ) {
            m = (l+r)/2;
            if ( f[m] > x ) { 
                r = m-1;
            } else if ( f[m] < x ) {
                l = m+1;
            } else { 
                return m;
            }
        }
        return -1;
    };
    cin >> q;
    for(int i=0; i<q; ++i) {
        cin >> x;
        int ans = mybin(0,n,x);
        cout << ans+1 << '\n';
    }
}