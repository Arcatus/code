#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string  suma(string a, string b);
string resta(string a, string b);

string borra_ceros(string s){
	while(s.length() > 0 && s[0]=='0' )
		s.erase( s.begin() );
	return s;
}

bool menor(string a, string b)
{
	if(a.length()==b.length()) return a<b;
	return a.length() < b.length();
}

string divide(string num, string den)
{
	int k = 0, i = den.length()-1;
	string coc, res = num.substr(0,den.length()-1);

	vector<string> tabla; tabla.push_back(den);

	vector<string>::iterator it;

	for (int j=1; j<9; j++ )
		tabla.push_back(suma(tabla[j-1],den));
	while( i<num.length() ){
		while( i<num.length() ){
			res+=num[i++];
				if (menor(res,den) ) coc+='0';
				else break;
		}
		if( !menor(res,den) ){
			it = lower_bound(tabla.begin(),tabla.end(),res,menor);
			int dig = it-tabla.begin();
			if( dig<9 && tabla[dig]==res ) coc+=(dig+1+'0');
			else	coc+=(dig+'0'), dig--;
			res = borra_ceros( resta(res,tabla[dig]) );
		}

	}
	return ((coc=borra_ceros(coc))==""? "0" : coc);
}

int main()
{
	string a = "6";

	string b = "3";

	cout << divide(a,b) << '\n';
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