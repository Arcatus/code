#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int primera_parte = 0;
	int segunda_parte = 0;

	int t;
	for (int i=0; i < n/2; ++i)
	{
		cin >> t;
		primera_parte += t;
	}

	for (int i=n/2; i < n; ++i)
	{
		cin >> t;
		segunda_parte += t;
	}	

	if ( primera_parte == segunda_parte )
	{
		cout << primera_parte << " " << "1" << '\n';
	} else {
		cout << primera_parte + segunda_parte << " " << "0" << '\n';
	}
}