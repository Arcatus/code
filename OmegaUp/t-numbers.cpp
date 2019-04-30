#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>

using namespace std;

typedef long long ll;

string borra_ceros(string s){
	while(s.length() > 0 && s[0]=='0' )
		s.erase( s.begin() );
	return s;
}

string mult(string a, string b){
	int n = a.size(), m = b.size();
	int t,k,i; string ans(m+n,'0');

	for (int j = m-1; j >= 0; j--){
		for (i = n-1, k = 0 ; i >= 0 ; i--){
			t = (a[i]-'0')*(b[j]-'0');
			t += (ans[i+j+1]-'0') + k;
			ans[i+j+1] = (t%10)+'0';
			k = t/10;
		}
		ans[j] = ( k + '0');
	}
	return ((ans=borra_ceros(ans))=="" ? "0":ans);
}

string suma (string a, string b)
{
	int l = 1 + (a.length() > b.length() ? a.length() : b.length());
	string c(l,'0');

	a = string(l - a.length(), '0' ) + a;
	b = string(l - b.length(), '0' ) + b;

	int ac = 0, sum = 0;

	for( int i = l - 1; i >= 0; i-- )
	{
		sum = ( a[i] - '0' ) + ( b[i] - '0') + ac;
		c[i] = (sum % 10) + '0';
		ac = sum / 10;
	}
	return ((c=borra_ceros(c))=="" ? "0":c);
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	ll n;

	cin >> n;

	ll tmp = n/2LL;

	string a = to_string(n);
	string b = to_string(tmp);

	string res = suma( mult(a,b), b );

	if ( n & 1LL )
	{
		cout << suma( res, a ) << '\n';
	}
	else
	{
		cout << res << '\n';
	}

	return 0;
}