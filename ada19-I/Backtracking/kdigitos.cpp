#include <iostream>

using namespace std;

int n, k;

int contador, suma;
int array[100+1];

void genera(int t, int ini)
{
	if ( t == k )
	{
		contador+=1;
	}
	else if(t == k-1)
	{
		int tmp = (n-suma);
		if (tmp >= array[t-1])
		{
			suma+=tmp;
			array[t] = tmp;
			genera(t+1,tmp);
			array[t] = 0;
			suma-=tmp;
		}
	}
	else
	{
		for (int i=ini; i<=n-k+1;++i)
		{
			if ( suma + i <= n && n-suma >= k - t ) {
				suma+=i;
				array[t] = i;
				genera(t+1,i);
				array[t] = 0;
				suma-=i;					
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);

	cin >> n >> k;
	genera(0,1);

	cout << contador << '\n';

	return 0;
}