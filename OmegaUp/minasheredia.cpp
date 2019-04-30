#include <iostream>

using namespace std;

int R, C;
int grid[200 + 2][200 + 2];
int res[200 + 2][200 + 2];

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> R >> C;

	for (int i=1;i<=R;++i)
	{	
		for(int j=1;j<=C;++j)
		{
			cin >> grid[i][j];
		}
	}
	int ans = 0;
	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			if (grid[r][c] & 1) {
				res[r][c] = 9;
				continue;
			}

			for (int d = 0; d < 8; d++)
			{
				ans += grid[ r + dr[d] ][ c + dc[d] ];
			}
			res[r][c] = ans;
			ans = 0;
		}
	}

	for (int i=1;i<=R;++i)
	{	
		for(int j=1;j<=C;++j)
		{
			cout << res[i][j]<< ' ';
		}
		cout << '\n';
	}
	return 0;
}