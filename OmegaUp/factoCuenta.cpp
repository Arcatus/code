#include <iostream>
#include <string>

using namespace std;


typedef long long ll;

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

int main()
{
	string facto = "1";

	ll n;
	scanf("%lld",&n);

	if ( n == 0)
	{
		printf("1\n");
	}
	else
	{
		string a = "1";
		string b = "2";

		string res = "1";

		for ( ll i = 1; i < n; i+=2 )
		{
			res  = mult ( res , mult(a,b) );
			a = suma(b,"1");
			b = suma(a,"1");
		}

		if (n%2==1)
		{
			res  = mult ( res , a );
		}

		cout << res << '\n';

		cout << n << "! tiene " << res.length() << " digitos" <<  '\n';
	}
}