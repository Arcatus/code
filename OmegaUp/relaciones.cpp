#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, t;

	cin >> n >> m;
	
	unordered_set<int> arr;
	unordered_set<int> brr;

	for(int i=0; i<n; ++i) {
		cin >> t;
		arr.insert(t);
	}
	for(int i=0; i<m; ++i) {
		cin >> t;
		brr.insert(t);
	}
	auto it1 = arr.begin();
	auto it2 = brr.begin();

	if ( arr.size() <= brr.size() ) {
		for( int i=0; i < arr.size(); ++i ) {
			if ( brr.find( *it1 ) == brr.end() ) {
				break;
			}
			it1++; it2++;
		}
		if ( it1 == arr.end() && it2 == brr.end() ) {
			cout << "A = B\n";
		} else if ( it1 == arr.end() ) {
			cout << "A < B\n";
		} else {
			cout << "A != B\n";
		}
	} else {
		for( int i=0; i < brr.size(); ++i ) {
			if ( arr.find( *it2 ) == arr.end() ) {
				break;
			}
			it2++;
		}
		if ( it2 == brr.end() ) {
			cout << "A > B\n";
		} else {
			cout << "A != B\n";
		}
	}
}