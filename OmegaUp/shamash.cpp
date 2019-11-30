#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll p;

	cin >> p;

	vector<string> v;
		
	ll a, b;

	do {
		a = p/60;
		b = p%60;

		int L = b/10;

		string ans = "";

		for(int i=0; i<L; ++i) {
			ans += "L";
		}
		
		int I = b%10;

		for(int i=0; i<I; ++i) {
			ans += "I";
		}
		v.push_back(ans);
		if ( a != 0 ) {
			v.push_back(".");
		}
		
		p = a;

	} while( p != 0 );

	for(int i=v.size()-1; i>=0; i--) {
		cout << v[i];
	}
}