#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;
	string s;
	for(int i=0; i<n; ++i) {
		cin >> s;
		if ( s[s.size()-1] == 'o' ) {
			cout << "FILIPINO\n";
		} else if ( s[s.size()-1] == 'u' ) {
			cout << "JAPANESE\n";
		} else {
			cout << "KOREAN\n";
		}
	}
}