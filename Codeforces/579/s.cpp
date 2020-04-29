#include <iostream>
#include <algorithm>

using namespace std;

string s, t;

bool posible[200+1];
int ans = -1;

void subcommon(int i, int j) {
	if ( i == s.size() || j == t.size() ) {
		
		if ( j != t.size() ) return;

		int partial=0;
		for(int i=0; i<s.size(); ++i) {
			if ( posible[i] == false ) {
				partial+=1;
			} else {
				partial = 0;
			}
			ans = max( ans, partial );
		}
		return;
	}
	if ( s[i] != t[j] ) {
		subcommon(i+1,j);
	} else {
		
		subcommon(i+1,j);

		if ( (s.size()-i >= t.size()-j ) && s[i] == t[j] ) {
			posible[i] = true;
			subcommon(i+1,j+1);
			posible[i] = false;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i=0; i<200+1; ++i) posible[i] = false;

	cin >> s;
	cin >> t;
	
	subcommon(0,0);

	cout << ans << '\n';
}