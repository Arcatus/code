#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;
 
int main() {
	string s, t;
	cin >> s >> t;
	int j = 0;

	vector<int> pos;

	pos.push_back(-1);

	for(int i=0; i < s.size(); i++) {
		if ( s[i] == t[j] ) {
			pos.push_back( i );
			j++;
		}
	}

	int ans = 0;
	j = 0;
	for( int i=s.size()-1; i>=0; i-- ) {
		
		ans = max( ans, i - pos[ pos.size() - 1 - j ] );		

		if ( j < t.size() && s[i] == t[ t.size() - j - 1 ] ) {
			j++;
		}
	}
	cout << ans << '\n';
}