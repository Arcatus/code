#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <iomanip>

typedef long long ll;
using namespace std;

inline double f(double x) {
    return 2*x*x - 12*x + 7;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    double l, r;
    for(int i=0; i<n; ++i) {
        cin >> l >> r;
        double mid1, mid2;
        while( r-l > 1e-9 ) {
            mid1 = l + (r-l)/3;
            mid2 = r - (r-l)/3;
            if ( f(mid1) > f(mid2) ) {
                l = mid1;
            } else {
                r = mid2;
            }
        }
        cout << fixed; cout << setprecision(0);
        cout << f(l) << '\n';
    }
}