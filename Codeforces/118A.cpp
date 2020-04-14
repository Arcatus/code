#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char s[100+1];
	
	cin >> s;

	auto isVowel = [] (char a) {
		if (a == 'A' || a == 'a' || 
			a == 'O' || a == 'o' ||
			a == 'Y' || a == 'y' || 
			a == 'E' || a == 'e' || 
			a == 'U' || a == 'u' ||
			a == 'I' || a == 'i' 
			) {
			return true;
		} else {
			return false;
		}
	};
	string ans;

	for(int i=0; s[i]; ++i) {
		if ( !isVowel(s[i]) ) {
			ans += s[i];
		}
	}

	for(int i=0; i < ans.size(); ++i) {
		cout << "." << char(tolower(ans[i]));	
	}
}