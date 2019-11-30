#include <iostream>

using namespace std;

typedef unsigned long long ll;

ll potencia_simplificado(ll a,ll b)
{
   if (b <= 1) {
      return (b == 0 ? 1 : a);
   }
   ll temp = potencia_simplificado(a, b / 2);
   ll res = temp * temp;
   return res * (b % 2 == 0 ? 1 : a);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	
	cin >> n;

	ll ans = 0;

	for(ll i = 1; i<=n; ++i) {
		ans += potencia_simplificado(i,i);
	}
	for(int i=0; i<7; ++i) {
		cout << ans%10;
		ans /= 10;
	}
}