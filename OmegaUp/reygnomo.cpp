#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n+1];
        for(int i=1; i<=n; ++i) cin >>a[i];
        int ans = 0;
        for(int i=2; i<n; ++i) {
            if ( a[i-1]+1 != a[i] ) {
                ans = i; break;
            }
        }
        cout << ans << '\n';
    }
}