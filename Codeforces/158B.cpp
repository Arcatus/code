#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int arr[n];

	int cuenta[5];

	fill(cuenta, cuenta+5, 0);
	int x;
	for(int i=0; i<n; ++i) {
		cin >> x;
		cuenta[x]++;
	}
	int ans = cuenta[4];

	int low = min(cuenta[3], cuenta[1]);

	ans += low;

	cuenta[3]-=low; cuenta[1]-=low;

	if ( cuenta[3] > 0 ) {
 		ans += cuenta[3];
	} else if( cuenta[1] > 0 ) {
		if ( cuenta[2] % 2 != 0 ) {
			if ( cuenta[1] <= 2 ) {
				cuenta[1] -= (cuenta[1]==2)? 2: 1;
				ans+=1;
			} else if ( cuenta[1] > 2 ) {
				ans+=1;
				cuenta[1] -= 2;
			}
			cuenta[2]-=1;
		}
		if ( cuenta[1] > 0 ) {
			if ( cuenta[1]%4 == 0 ) {
				ans += cuenta[1]/4;
			} else {
				ans += cuenta[1]/4 + 1;
			}
		}
	}
	if ( cuenta[2]%2 != 0 ) {
		ans+=1;
	}

	ans += cuenta[2]/2;


	cout << ans << '\n';
}	