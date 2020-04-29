#include <bits/stdc++.h>

using namespace std;

bool isInside(double x, double y, double z, double r) {
    if ( x*x + y*y + z*z <= r*r ) {
        return true;
    } else {
        return false;
    }
}

struct point {
    double x, y, z;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;   
    double x, y, z;
    point L[n];
    for(int i=0; i<n; ++i) {
        cin >> L[i].x >> L[i].y >> L[i].z;
    }
    int cnt; bool ispos;
    double lo = 1.0, hi = sqrt(3.0)*1000000.0;
    while( abs(hi-lo) > 1e-6 ) {
        double m = lo + (hi-lo)/2.0;
        cnt = 0;
        ispos = false;
        for(int i=0; i<n; ++i) {
            if ( isInside(L[i].x,L[i].y,L[i].z,m) ) {
                cnt++;
            }
            if (cnt == k) {
                ispos = true;
                break;
            }
        }
        if ( ispos ) {
            hi = m;
        } else {
            lo = m;
        }
    }
    cout.precision(8);
    cout << fixed << lo << '\n';
    return 0;
}