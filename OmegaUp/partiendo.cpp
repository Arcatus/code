#include <iostream>
#include <climits>
using namespace std;

typedef long long ll;

ll minz(const ll& a, const ll& b) {
	if (a!=0 && b!=0) {
		return min(a,b);
	}
	else if ( a == 0 && b!= 0 ) {
		return b;
	} else if ( b == 0 && a != 0 ) {
		return a;
	} else {
		return INT_MAX;
	}
}

int letras[126+1];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char c;

	while(cin >> c) {
		letras[c]++;
	}
	ll ans = 0;
	ll mini = INT_MAX;
	for (int i = 0; i < 127; ++i) {
		ans += letras[i];
		mini = minz(letras[i], mini);
	}
	cout << ans - mini << '\n';
}