#include <iostream>

int BIT[100000], n;
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int m, i, I, U;

	short tmp;

	std::cin >> n;

	for (i = 1; i <= n; ++i)
	{
		std::cin >> tmp;

		for(int k = i; k <= n; k += k&-k)
		{
			BIT[k] += tmp;
		}
	}

	std::cin >> m;

	for (i = 0; i < m; ++i)
	{
		std::cin >> I >> U;

		std::cout << query(U+1) - query(I) <<'\n';
	}
}