#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; ++i) {
		cin >> arr[i];
	}
	int ans = 0;
	int cnt = 0;
	while( true ) {
		int l = 0, r = n-1, to_changue_L = 0, to_changue_R = 0, lin, rin;
		while( l < n && arr[l] == 1 ) l++;
		while( l < n ) {
			if ( arr[l] == 1 ) {
				to_changue_L = 0;
				lin = l;
				while( l < n && arr[l] == 1 ) {
					l++; to_changue_L++;
				}
			} else l++;
		}
		//cerr << to_changue_L << '\n';
		while( r >= 0 && arr[r] == 2 ) r--;
		while( r >= 0 ) {
			if ( arr[r] == 2 ) {
				to_changue_R = 0;
				rin = r;
				while( r >= 0 && arr[r] == 2 ) {
					r--; to_changue_R++;
				}
			} else r--;
		}
		//cerr << to_changue_R << '\n';

		if ( to_changue_L == 0 || to_changue_R == 0 ) {
			break;
		} else if ( to_changue_L < to_changue_R ) {
			for(int i=0; i<to_changue_L; ++i) {
				ans++;
				arr[i + lin] = 2;
			}
		} else {
			for(int i=0; i<to_changue_R; ++i) {
				ans++;
				arr[rin - i] = 1;
			}
		}
	} 
	cout << ans << '\n';
	return 0;
}