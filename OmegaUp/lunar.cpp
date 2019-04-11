#include <iostream>

using namespace std;

// true return b; false return a
bool compMax(char a, char b)
{
	return a<b;
}

// true return a; false return b
bool compMin(char a, char b)
{
	return !(b<a);
}

string borra_ceros(string s){
	while(s.length() > 0 && s[0]=='0' )
		s.erase( s.begin() );
	return s;
}

string suma(string a, string b)
{
	int l = max(a.length(),b.length(),compMax);

	string ans(l,'0');

	a = string(l-a.length(),'0')+a;
	b = string(l-b.length(),'0')+b;

	for (int i = l - 1; i >= 0; i--)
	{
		ans[i] =(char) max(a[i],b[i],compMax);
	}
	return ((ans=borra_ceros(ans))=="" ? "0":ans);
}

string mult(string a, string b)
{
	int i, j; char t;
	int n = a.length(), m = b.length();
	string ans(n+m-1,'0');

	for (j = m-1; j >= 0; j--){
		for (i = n-1; i >= 0 ; i--){
			t =(char) min(a[i],b[j],compMin);
			t =(char) max(ans[i+j],t,compMax);
			ans[i+j] = t;
		}
	}
	return ((ans=borra_ceros(ans))=="" ? "0":ans);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, op;
	cin >> n;
	string a, b;
	for (int i=0; i<n; ++i) {
		cin >> op;
		cin >> a >> b;

		if (op==1) {
			
			cout << suma(a,b) << '\n';
		} else {			
			cout << mult(a,b) << '\n';
		}
	}
}