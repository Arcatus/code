#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int x=0, y=0, z=0;
	int a=0, b=0, c=0;

	for(int i=0; i<n; ++i) {
		cin >> x >> y >> z;
		a+=x;
		b+=y;
		c+=z;
	}
	if ( a==0 && b==0 && c==0 ) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}