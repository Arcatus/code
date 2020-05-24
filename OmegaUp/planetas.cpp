#include <bits/stdc++.h>
using namespace std;

int n;
double a[1000+1];
inline double f(double x) {
    double ans = 0.0;
    for(int i=0; i<n; ++i) {
        if ( a[i] < x ) {
            ans += - ( 1 / abs( x - a[i] ) );
        } else {
            ans +=   ( 1 / abs( x - a[i] ) );
        }
    }
    return abs(ans);
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%lf",&a[i]);
    }
    sort(a, a+n);
    vector<double> ans;
    double l, r;
    for(int i=0; i<n-1; ++i) {
        l = a[i]+0.001; r = a[i+1]-0.001;
        double mid1, mid2;
        while( r - l > 1e-9 ) {
            mid1 = l + (r-l)/3;
            mid2 = r - (r-l)/3;
            if ( f(mid1) < f(mid2) ) {
                r = mid2;
            } else {
                l = mid1;
            }
        }
        ans.push_back(l);
    }
    printf("%d\n",ans.size());
    for(double i: ans) {
        printf("%.3lf ",i);
    }
    printf("\n");
    return 0;
}