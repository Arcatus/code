#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a;

	cin >> a;
	int cnt = 0;
	for(int i=0; i<a.size(); ++i) {
		if( a[i] == 'a' ) {
			cnt+=1;
		}
	}

	if ( cnt > a.size()/2 ) {
		cout << a.size() << '\n';
	} else {
		cout << cnt+cnt-1 << '\n';
	}
}	