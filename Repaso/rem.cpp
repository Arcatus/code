#include <iostream>

using namespace std;

typedef long long ll;

struct tup3 { ll x, y, z; };

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a*(b / gcd(a, b)); }

tup3 extgcd(ll a, ll b)
{
    if( b == 0 ) return {1,0,a};
    tup3 t = extgcd(b, a%b);
    return {t.y, t.x - (a/b)*t.y, t.z};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll a, n, b, m;
        cin >> a >> n >> b >> m;
        ll g = gcd(n,m);
        
        if ( (a - b)%g == 0 ) {
            tup3 c = extgcd(n/g,m/g);
            ll l = lcm(n,m);
            ll ans = ( a*(m/g)*c.y + b*(n/g)*c.x ) % l;
            if ( ans < 0) ans += l;
            cout << ans << " " << l << '\n';
        } else {
            cout << "no solution\n";
        }
    }
}