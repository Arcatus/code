#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n[4];

	for(int i=0; i<4; ++i) {
		cin >> n[i];
	}

	//for(int i=0; i<4; ++i) { cout << n[i] << ' ';} cout << '\n';

	string s;

	cin >> s;

	//cout << s << '\n';

	int ans = 0;

	for(int i=0; i < s.size(); ++i) {
		//cout << n[ s[i] - '0' - 1] << ' '; 
		ans += n[ s[i] - '0' - 1];
	}

	cout << ans << '\n';
}