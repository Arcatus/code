#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string borra_ceros(string s){
	while(s.length() > 0 && s[0]=='0' )
		s.erase( s.begin() );
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a;
	cin >> a;
	a = string(3 - (int)a.length(),'0') + a;

	reverse(a.begin(),a.end());

	cout << borra_ceros(a) <<'\n';
}