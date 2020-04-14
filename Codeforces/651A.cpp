#include <iostream>
#include <cstring>
using namespace std;

int memo[200][200];

int solve(int a, int b) {
	if ( a <= 0 || b <= 0 ) {
		return 0;
	} else {
		if ( a > b ) swap(a,b);
		if ( memo[a][b] == -1 ) {
			memo[a][b] = max(1+solve(a-2,b+1) , 1+solve(a+1,b-2));
		}
		return memo[a][b];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;

	cin >> a >> b;

	memset(memo, -1, sizeof memo);

	memo[1][1] = 0;
	
	int ans = solve(a, b);

	cout << ans << '\n';
}