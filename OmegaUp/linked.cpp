#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, t;
	cin >> n;

	char opc[13];

	list<int> milista;

	for (int i=0;i<n;++i)
	{
		cin >> opc;
		cin >> t;

		if (opc[0] == 'A')
		{
			if (opc[7] == 'I') {
				milista.push_front(t);
			}
			else 
			{
				milista.push_back(t);
			}
		}
		else
		{
			if (opc[6] == 'P') {
				auto it = find( milista.begin(), milista.end(), t );
				milista.erase(it);
			}
			else 
			{
				auto it = find( milista.rbegin(), milista.rend(), t );
				milista.erase((++it).base());
			}
		}
	}

	for (auto i: milista)
	{
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}