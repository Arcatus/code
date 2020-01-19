#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;

	int diff = min(a,b);

	a -= diff;
	b -= diff;
	
	cout << diff << " " << a/2 + b/2 << '\n';
}