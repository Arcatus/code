#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	char s[n+1];

	cin >> s;
	int a=0;
	int b=0;
	for(int i=0; s[i]; ++i) {
		if (s[i] == 'A') {
			a +=1;
		} else {
			b +=1;
		}
	}
	if ( a == b ) {
		cout << "Friendship" << '\n';
	} else if ( a > b) {
		cout << "Anton" << '\n';
	} else {
		cout << "Danik" << '\n';
	}
}