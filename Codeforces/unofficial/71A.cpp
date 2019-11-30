#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string a;	
	for(int i=0; i<n; ++i) {
		cin >> a;
		if (a.size() > 10 ) {
			cout << a[0] << a.size()-2 << a[a.size()-1] << '\n';
		} else {
			cout << a << '\n';
		}
	}
}