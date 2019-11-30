#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ascii[25+1];

	fill(ascii, ascii+25+1, 0);
 	
 	string s;

 	cin >> s;

 	for(int i=0; i<s.size(); ++i) {
 		ascii[s[i]-'a'] = 1;
 	}
 	int ans=0;
 	for(int i=0; i<26; ++i) {
 		ans += ascii[i];
 	}
 	if ( ans&1 ) {
 		cout << "IGNORE HIM!\n";
 	} else {
 		cout << "CHAT WITH HER!\n";
 	}
}