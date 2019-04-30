#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	short n, i;
	cin >> n;
	short carta;

	vector<short> v(14,4);

	short ans(0);
	for (i=0;i<n;++i) {
		cin >> carta;
		ans += carta;
		v[carta]--;
	}

	short x = 21 - ans;

	short greaterThan=0, lessThan=0;

	for (i=2;i<=x;i++){
		lessThan += v[i];
	}
	for (i=x+1;i<=13;i++){
		greaterThan += v[i];
	}
	greaterThan+=4; // Aces
	//cout << greaterThan << " " << lessThan <<'\n';
	if ( greaterThan >= lessThan) {
		cout << "DOSTA" << '\n';
	}
	else {
		cout << "VUCI" << '\n';
	}
	return 0;
}