#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;

	cin >> t;

	char telephone[100+1];

	while( t-- ) {
		int n; 
		cin >> n;
		cin >> telephone;
		
		bool flag = false;

		for(int i=0; telephone[i]; ++i) {
			if ( telephone[i] == '8' ) {
				if ( strlen(telephone) - i > 10 ) {
					flag = true;
					break;
				}
			}
		}
		if ( flag ){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}