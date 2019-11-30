#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct lista{
	int* elementos;
};

struct position{
	int x, y;
	int num;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int l, n, k;

	cin >> l >> n >> k;

	lista torre[l];

	position id[l*n];

	for (int i=0;i<l;++i)
	{
		torre[i].elementos = new int[n];
		for (int j=0;j<n;++j)
		{
			cin >> torre[i].elementos[j];
			id[i*n + j].y = i;
			id[i*n + j].x = j;
			id[i*n + j].num = torre[i].elementos[j];
		}
	}

	sort( id, id + (l*n), [](const position& a, const position& b){
		return a.num < b.num;
	} );

	for (int i=0;i<k-1;++i)
	{
		torre[ id[i].y ].elementos[ id[i].x  ] = -1;
	}

	vector<int> torneo;

	for (int i=0;i<l;++i)
	{
		for (int j=0;j<n;++j)
		{
			if ( torre[i].elementos[j] != -1 )
			{
				torneo.push_back( torre[i].elementos[j] );
				goto skip;
			}
		}
		torneo.push_back(-1);
		skip:;
	}
	int size = torneo.size();

	for (auto j: torneo) cout << j << ' ';
			cout << '\n';

	while( size != 1 )
	{
		vector<int> ans;

		for(int i=0; i < size; i+=2)
		{
			if ( torneo[i] == -1)
			{
				ans.push_back(torneo[i+1]);
			}
			else if ( torneo[i+1] == -1)
			{
				ans.push_back(torneo[i]);
			}
			else if ( torneo[i] < torneo[i+1] )
			{
				ans.push_back(torneo[i]);
			}
			else
			{
				ans.push_back(torneo[i+1]);
			}
		}
		for (auto j: ans) cout << j << ' ';
			cout << '\n';
		size = ans.size();

		torneo.swap(ans);
	}	
}