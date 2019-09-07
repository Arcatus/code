#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	string days;
	cin >> days;

	int state = 0;

	int ansF = 0;
	int ansS = 0;

	for(int i=0; i < days.size()-1; ++i) {
		if ( days[i] != days[i+1]  ) {
			if ( days[i+1] == 'F' ) {
				ansF += 1;
			} else {
				ansS += 1;
			}
		}
	}
	if ( ansF > ansS ) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}