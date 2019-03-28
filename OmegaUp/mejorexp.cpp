#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>

using namespace std;

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
	int k;

	cin >> k;

	int t; 

	string max = "0";

	for (int i = 0; i < k; ++i)
	{
		cin >> t;

		string n = to_string(t);

		string exp = to_string(t-1);

		string base = n;

		for ( int j = 0; j < t-1; ++j )
		{
			 n = mult(n,base);
		}
		if ( ! menor(n,max) )
		{
			max = n;
		}
	}

	cout << max << '\n';

}