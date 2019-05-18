#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>
//#include <vector>
//#include <string>

using namespace std;

typedef long long ll;
//typedef vector<int> vi;

ll producto(ll a, ll b);
ll productoDigito(ll a, ll b);

ll suma(ll a, ll b)
{
	if (a == 0 && b == 0)
		return 0;
	else
		return max(a%10,b%10) + 10*suma(a/10,b/10);
}

ll producto(ll a, ll b)
{
	if ( a == 0 )
		return 0;
	return suma(  productoDigito(a%10,b) , 10*producto(a/10,b) );
}

ll productoDigito(ll a, ll b)
{
	if ( b == 0 )
		return 0;
	return min(a,b%10)+ 10*productoDigito(a,b/10);

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, op, a, b;
	cin >> n;
	for (ll i=0; i <n; ++i)
	{
		cin >> op;

		if (op==1)
		{
			cin >> a >> b;
			cout << suma(a,b) << '\n';
		}
		else if(op==2)
		{
			cin >> a >> b;
			cout << producto(a,b) << '\n';
			
		}
	}
}