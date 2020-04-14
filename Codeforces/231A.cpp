#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans=0;
	int x, t;
	for(int i=0; i<n; ++i) {
		t = 0;
		for(int j=0;j<3;++j) {
		 	cin >> x;
			t +=x;
		}
		if ( t >= 2 ) {
			ans +=1;
		}
	}
	cout << ans << '\n';
}