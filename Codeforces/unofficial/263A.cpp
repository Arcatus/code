#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int opc;

	for(int i=1; i<=5; ++i) {
		for(int j=1; j<=5; ++j) {
			cin >> opc;
			if (opc == 1) {
				cout <<  abs( 3 - abs(i) ) + abs(3 - abs(j) ) << '\n';
				return 0;
			}
		}
	}

}