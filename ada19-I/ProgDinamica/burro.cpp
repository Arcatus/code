#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


int arr[500];
bool dp[25000+1];
int n, ans, izq, der, suma;

void tabla(int k)
{
	for (int i=suma;i>=0;--si)
	{
		if ( i >= k && ( dp[i] ||  ) ) 
		{

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i=0;i<n;++i)
	{
		cin >> arr[i];
	}
	izq = accumulate(arr,arr+n);

	sort(arr,arr+n);

	dp[0] = true;

	for(int i=0;i<n;++i) tabla(arr[i]);

	for (int i=0; i <= suma/2 + 1; ++i)
	{
		if ( oraculo(i) )
		{
			 
		}
	}

	return 0;
}