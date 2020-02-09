#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;

	string s;

	int i;

	vector<string> bd;

	bool f = false;

	for(i=0; i<n; ++i) {
		cin >> s;
		size_t found = s.find("OO");

		if( found != string::npos ) {
			s[found]='+';
			s[found+1]='+';
			bd.push_back( s );
			f = true;
			break;
		} else {
			bd.push_back( s );
		}
	}
	while( ++i < n ) {
		cin >> s;
		bd.push_back( s );
	}

	if( f ) {
		cout << "YES\n";
		for(string k: bd) {
			cout << k << '\n';
		}
	} else {
		cout << "NO\n";
	}
}