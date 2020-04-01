#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0LL;
    for(int i=1; i<=n; ++i) {
        ans += i*(i+1) / 2;
    }
    cout << ans << '\n';
}