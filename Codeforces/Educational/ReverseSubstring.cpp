#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;

	for(int i=0; i<s.size()-1; ++i) {
		 if ( s[i] > s[i+1] ) {
		 	cout << "YES\n";
		 	cout << i+1 << " " << i+2 << '\n';
		 	return 0;
		 }
	}
	cout << "NO\n";
}