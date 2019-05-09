#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int pos;

	vector<pair<bool,int>> puertas(100001);

	for (int i=1;i<=n;++i)
	{
		cin >> pos;
		puertas[pos] = { true, i };
	}
	int m;
	cin >> m;
	for (int i=0;i<m;++i)
	{
		cin >> pos;
		if ( puertas[pos].first )
			cout << puertas[pos].second << ' ';
		else
			cout << '0' << ' ';
	}
	cout <<'\n';
	return 0;
}
