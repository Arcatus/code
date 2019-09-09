#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;

	cin >> s;

	string a = "hello";
	int i, j;
	for(i=0, j=0; i<s.size() && j < a.size();++i) {
		if ( s[i] == a[j] ) {
			j+=1;
		}
	}	
	cout << (j == 5 ? "YES" : "NO") << '\n';
}