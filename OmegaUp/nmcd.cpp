#include <iostream>

using namespace std;

int gcd( int a, int b ){
	return ( b == 0)? a: gcd(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	int ans=0;
	int x;
	while( n-- ){
		cin >> x;
		ans = gcd(ans,x);
	}
	cout << ans << '\n';
}