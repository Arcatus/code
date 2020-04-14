#include <iostream>

using namespace std;

int main() 
{
	int n;

	cin >> n;

	int p1=0, p2=0;
	int a, b;
	for(int i=0; i<n; ++i) {
		cin >> a >> b;
		if ( a > b ) {
			p1++;
		} else if ( a < b ) {
			p2++;
		} 
	}
	if( p1 > p2 ) {
		cout << "Mishka\n";
	} else if ( p1 < p2 ) {
		cout << "Chris\n";
	} else {
		cout << "Friendship is magic!^^\n";
	}
}