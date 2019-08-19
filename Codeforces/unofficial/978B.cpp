#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int n;
	cin >> n;
	cin >> s;
	int x = 0;
	int ans=0;
	int contador=0;

	for(int i=0; i<s.size(); ++i) {
		if ( s[i] == 'x') {
			contador+=1;
		} else {
			contador=0;
		}
		if ( contador == 3 ) {
			ans+=1;
			contador-=1;
		}
	}
	cout << ans << '\n';
}