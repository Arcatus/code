#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>

using std::string;
using std::cin;
using std::cout;

string borra_ceros(string s){
	while(s.length() > 0 && s[0]=='0' )
		s.erase( s.begin() );
	return s;
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
	string a, b;

	cin >> a >> b;

	for(auto& i : a)
	{
		if ( i == '6' )
		{
			i = '5';
		}
	}

	for(auto& i : b)
	{
		if ( i == '6' )
		{
			i = '5';
		}
	}

	std::cout << suma(a,b) << ' ';

	for(auto& i : a)
	{
		if ( i == '5' )
		{
			i = '6';
		}
	}

	for(auto& i : b)
	{
		if ( i == '5' )
		{
			i = '6';
		}
	}	

	std::cout << suma(a,b) << '\n';
}