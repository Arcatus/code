#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << 0 << '\n';
	int ans;
	for (int i=1;i<=100;++i)
	{
		ans = 0;
		for ( int j=1;j<=100;++j )
		{
			if (i % j == 0)
			{
				ans += 1;
			}
		}
		cout << i << " tiene: " << ans << '\n';
	}
	return 0;
}