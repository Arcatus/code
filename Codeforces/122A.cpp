#include <iostream>
#include <vector>
using namespace std;


bool lucky(int k) {
	while( k ) {
		int l = k%10;
		if ( l==4 || l==7 ){
			k /= 10;
		} 
		else return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	vector<int> divisors;

	for(int i=1; i*i <= n; ++i) {
		if ( n%i != 0 ) continue;
		divisors.push_back(i);
		if ( n/i != i ) divisors.push_back(n/i);
	}
	for(int i: divisors) {
		if ( lucky(i) ) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}