#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a;

	cin >> a;

	int x=0;
	int y=0;

	for(int i=0; i<a.size(); ++i) {
		if ( x == 6 && a[i] == '1'  ) {
			cout << "YES\n";
			return 0;
		} else if ( y == 6 && a[i] == '0' ){
			cout << "YES\n";
			return 0;
		}
		if ( a[i] == '0') {
			x = 0;
			y+=1;
		} else {
			y = 0;
			x+=1;
		}
	}
	
	cout << "NO\n";
}