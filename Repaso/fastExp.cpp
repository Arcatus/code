#include <iostream>

using namespace std;

typedef long ll;

ll fastExponentiation(ll a, ll b) {
    if (b <= 1) {
        return (b==0)?1:a;
    }
    ll tmp = fastExponentiation(a,b/2);
    tmp = tmp*tmp;
    return (b&1)?tmp*a:tmp;
}

int main()
{
    //ll a, b;
    ll k, n, r;

    //cin >> a >> b;

    cin >> k >> n >> r;

    ll ans = fastExponentiation(k,n)*r;

    cout << ans << '\n';
}