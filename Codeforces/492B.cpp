#include <iostream>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, l;
    cin >> n >> l;
    
    double arr[n+2];
    arr[0] = -1.0;
    
    for(int i=1; i<=n; ++i) cin >> arr[i];
    
    arr[n+1] = (double)l;
    
    sort(arr,arr+n+2);
    
    arr[0] = 0.0, arr[n+1] = (double)l;
    double ans = -1.0;
    ans = (double)arr[1] - arr[0];
 
    for(int i=2; i<n+1; ++i) {
        ans = max(ans, abs(arr[i] - arr[i-1])/2.0);
    }
    ans = max(ans, (double)arr[n+1] - arr[n]);
 
    cout << fixed << ans << '\n';
}