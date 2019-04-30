#include <iostream>
#include <string>

using namespace std;

string query;
string l[1001];
bool print;
int i, j, n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (i=0;i<n;++i)
	{
		cin >> l[i];
	}

	cin >> query;

	for (i=0;i<n;++i)
	{
		print=true;
		for (j=0; j<query.length(); ++j)
		{
			if ( l[i][j] != query[j] )
			{
				print = false;
				break;
			}
		}
		if (print) cout << l[i] <<'\n'; 
	}

	return 0;
}