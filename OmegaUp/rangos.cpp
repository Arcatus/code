#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>


typedef unsigned long long ll;

using namespace std;

int main()
{
	int n;

	scanf("%d",&n);

	if (n == 1)
	{
		printf("0\n");
	}
	else if (n == 2)
	{
		printf("4\n");
	}
	else
	{
		ll* arr = new ll[2*n];

		arr[0] = 0;

		for (int i = 1; i <= n; ++i)
		{
			arr[i] += i + arr[i - 1];
		}

		for (int i = n + 1, k = n-1; i <= 2*n - 1; ++i,k--)
		{
			arr[i] += arr[ i - 1] + k;
		}

		unsigned long long res = 0;

		for (int i = 0; i < n - 1; ++i)
		{
			res += arr[n+1 + i] - arr[i];
		}
		cout << res <<'\n';
	}
}