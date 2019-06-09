#include <iostream>
#include <algorithm>

using namespace std;


/* 100A
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b, n;

	cin >> n;

	for (int j=0; j<n; ++j)
	{
		cin >> a >> b;

		int res = 0;

		for (int i=a;i<=b;++i)
		{
			string t = to_string(i);

			res += count(t.begin(), t.end(), '1');
		}	
		cout << res << '\n';
	}
	return 0;
}
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, n, k, res, last;

	cin >> n;

	for (int j=0; j<n; ++j) 
	{
		cin >> a >> b;

		res = 0;

		for (int i=a;i<=b;++i)
		{
			k = i;
			while(k)
			{
				last = k % 10;
				//cerr << "last: " << last << '\n';
				//cerr << "k: " << k << '\n';

				if ( last == 1 )
				{
					res += 1;					
				}
				k /= 10;
			}
		}
		cout << res << '\n';
	}
	return 0;
}