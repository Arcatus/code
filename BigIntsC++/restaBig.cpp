#include <iostream>
#include <string>

using namespace std;

string borra_ceros(string s){
	while(s.length() > 0 && s[0]=='0' )
		s.erase( s.begin() );
	return s;
}

string resta (string a, string b)
{
	int l = (a.length() > b.length() ? a.length() : b.length());
	string c(l,'0');

	a = string(l - a.length(), '0' ) + a;
	b = string(l - b.length(), '0' ) + b;

	int ac = 0, sum = 0;

	for( int i = l - 1; i >= 0; i-- )
	{
		sum = ( a[i] - '0' ) - ( b[i] - '0') - ac;
		c[i] = (sum + 10)%10 + '0';
		ac = sum<0;
	}
	return ((c=borra_ceros(c))=="" ? "0":c);
}

int main()
{
	string a = "15";
	string b = "4";

	cout << resta(a,b) << '\n';
}