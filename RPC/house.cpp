#include <bits/stdc++.h>

using namespace std;

string borra_ceros(string s) {
	while(s.length() > 0 && s[0]=='0' )
		s.erase( s.begin() );
	return s;
}

string mult(string a, string b) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if ( s.size() > 4 ) {
        string ans = mult( s, suma( mult( "3",s ), "1") );
        int num = stoi(ans.substr(ans.size()-4,4));
        num = num / 2;
        while( (num % 4) != 0 ) {
            ans = mult( s, suma( mult( "3",s ), "1") );
            num = stoi(ans.substr(ans.size()-4,4));
            num = num / 2;
            if (num%4 != 0) s = suma(s,"1");
        }
        cout << s << '\n';
    } else {
        long long n = stoul(s);
        long long num = n*(3*n + 1) / 2;
        while( num % 4 != 0 ) {
            num = n*(3*n + 1) / 2;
            if ( num % 4 != 0 ) n++;
        }
        cout << n << '\n';
    }
    return 0;
}