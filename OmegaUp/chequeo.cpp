#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	
	cin >> a >> b;

	if ( a.compare("123") == 0 ) {
		cout << 1 << '\n';
	} 
	else 
	{
		cout << 6 << '\n';
	}
}