#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    ll n, k;
    while(t--)
    {
        cin >> n >> k;
        if (k == 1) {
            for(ll i=0; i<n-2; ++i) cout << "a";
            cout << "bb\n";            
        } else {
            ll p = 1;
            ll oldp = 1;
            while( k > (p+1)*(p+2)/2 ) {
                oldp = p;
                p++;
            }
            oldp=p, p++;

            ll fb = k - ( oldp*(oldp+1)/2 + 1 );

            char ans[n]; memset(ans, 'a', sizeof ans);

            ans[n] = 0;            

            ans[n-1-fb] = 'b';
            ans[n-1-p] = 'b';
            cout << ans << '\n';
        }
    }
}