#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

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

bool menorValor(string a, string b)
{
	cout << a << " " << b << '\n';
	if(a.length()==b.length()) return a[0]<b[0];
	return a.length() < b.length();
}

string resta (string a, string b)
{
	ll l = (a.length() > b.length() ? a.length() : b.length());
	string c(l,'0');

	a = string(l - a.length(), '0' ) + a;
	b = string(l - b.length(), '0' ) + b;

	ll ac = 0, sum = 0;

	for( ll i = l - 1; i >= 0; i-- )
	{
		sum = ( a[i] - '0' ) - ( b[i] - '0') - ac;
		c[i] = (sum + 10)%10 + '0';
		ac = sum<0;
	}
	return ((c=borra_ceros(c))=="" ? "0":c);
}


string mult(string a, string b){
	ll n = a.size(), m = b.size();
	ll t,k,i; string ans(m+n,'0');

	for (ll j = m-1; j >= 0; j--){
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
	ll l = 1 + (a.length() > b.length() ? a.length() : b.length());
	string c(l,'0');

	a = string(l - a.length(), '0' ) + a;
	b = string(l - b.length(), '0' ) + b;

	ll ac = 0, sum = 0;

	for( ll i = l - 1; i >= 0; i-- )
	{
		sum = ( a[i] - '0' ) + ( b[i] - '0') + ac;
		c[i] = (sum % 10) + '0';
		ac = sum / 10;
	}
	return ((c=borra_ceros(c))=="" ? "0":c);
}


string divide(string num, string den)
{
	ll k = 0, i = den.length()-1;
	string coc, res = num.substr(0,den.length()-1);

	vector<string> tabla; tabla.push_back(den);

	vector<string>::iterator it;

	for (ll j=1; j<9; j++ )
		tabla.push_back(suma(tabla[j-1],den));
	while( i<num.length() ){
		while( i<num.length() ){
			res+=num[i++];
				if (menor(res,den) ) coc+='0';
				else break;
		}
		if( !menor(res,den) ){
			it = lower_bound(tabla.begin(),tabla.end(),res,menor);
			ll dig = it-tabla.begin();
			if( dig<9 && tabla[dig]==res ) {
				coc+=(dig+1+'0');	
			} else {
				coc+=(dig+'0'), dig--;
			}
			cout << res  << " - " << tabla[dig] << " = "<< resta(res,tabla[dig]) << '\n';

			if (!menorValor(res,tabla[dig])) cout << "NO ESTAN ORDENADOS\n";

			res = borra_ceros( resta(res,tabla[dig]) );
			
		}
	}
	return ((coc=borra_ceros(coc))==""? "0" : coc);
}

int main()
{
	string n;

	cin >> n;

	string ans = mult( n, suma(n,"1"));

	string res = divide(ans,"2");	

	cout << res << '\n';

	return 0;
}