#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int t=0;

	while(n != 1)
	{
		t++;
		cout << n << '\n';
		if ( n & 1){
			n*=3;
			n+=1;
		}
		else
			n >>= 1;
	}	
	cout << n << '\n';

	return 0;
}