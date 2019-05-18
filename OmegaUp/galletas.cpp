#include <iostream>	

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, g;

	cin >> a >> g;
	int suma=0, t;
	for (int i=0;i<a;++i)
	{
		for (int j=0;j<g;++j)
		{
			cin >> t;
			suma += t;
		}
		cout << suma << '\n';
		suma=0;
	}
	
	return 0;
}