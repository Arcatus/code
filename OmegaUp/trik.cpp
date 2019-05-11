#include <iostream>

using namespace std;

bool a[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char mov;

	a[0] = true;

	while(cin>>mov) {
		if ( mov=='A') {
			swap(a[0],a[1]);
		}
		else if ( mov=='B') {
			swap(a[2],a[1]);
		}
		else {
			swap(a[2],a[0]);
		}
	}

	for (int i=0;i<3;++i)
	{	
		if (a[i] == true) 
			cout << i + 1 << '\n';
	}	
	return 0;
}