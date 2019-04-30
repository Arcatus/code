#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int a, b, n, casos, i;

unordered_map< int, unordered_set<int> > tab;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (i=0;i<n;++i)
	{
		cin >> a >> b;
		tab[a].insert(b);
		tab[b].insert(a);
	}
	cin >> casos;
	for (i=0;i<casos;++i)
	{
		cin >> a >> b;

		if ( tab[a].count(b) > 0 )
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}