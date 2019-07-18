#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int,int> ii;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, l, d;

	cin >> c >> l >> d;

	vector< pair<int,int> > actual;

	actual.push_back( { 0, 0 } );

	ii costo[d+1];

	for (int i=0; i<=d; ++i) {
		costo[i].first = INT_MAX;
	}

	costo[0].first = 0;
	costo[0].second = -2;

	int dx[] = { -l, -c, c, l };

	for (int i=0; !actual.empty(); ++i )
	{
		vector< pair<int,int> > siguiente;

		for (int k=0; k<actual.size(); ++k) {
			if ( actual[k].first == d) {
				cout << actual[k].second << '\n';
				vector<int> steps;
				do {
					steps.push_back( costo[ d ].second );
					d = d - costo[ d ].second;
				} while(d != 0);

				for (int i=steps.size()-1; i>=0; --i) {
					cout << steps[i] << ' ';
				}
				cout << '\n';
				return 0;
			}
			for (int f=0; f<4; ++f )
			{
				if ( 0 <= actual[k].first + dx[f] && actual[k].first + dx[f] <= d )
				{
					if ( actual[k].second + 1 < costo[ actual[k].first + dx[f] ].first )
					{
						siguiente.push_back( { actual[k].first+dx[f], actual[k].second+1 } );
						costo[ actual[k].first + dx[f] ].first = actual[k].second+1;
						costo[ actual[k].first + dx[f] ].second = dx[f];
					}
				}		
			}
		}
		actual.swap(siguiente);
	}
}