#include <iostream>
#include <string>

using namespace std;

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

int main()
{
	int n;
	scanf("%d",&n);

	string resultado_parcial = "1";

	if (n == 0)
	{
		printf("1\n");
	}
	else
	{
		for (int i = 0; i < n ; ++i )
		{
			resultado_parcial = mult("2",resultado_parcial);
		}

		std::cout << resultado_parcial << '\n';
	}

	return 0;
}