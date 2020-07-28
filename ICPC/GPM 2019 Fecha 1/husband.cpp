#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, T;
	cin >> n >> T;

	int arr[n];

	for (int i=0;i<n;++i)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);

	int menores=0;
	int contador_menores=0;
	for (int i=0;i<n;++i)
	{
		if (menores + arr[i] < T)
		{
			contador_menores+=1;
			menores+=arr[i];
		} else break;
	}

	auto it = lower_bound(arr,arr+n,T) - arr;

	int mayores=0;
	int contador_mayores=0;

	for (int i=it-1;i>=0;i--) {
		if ( mayores + arr[i] < T ) {
			contador_mayores+=1;
			T -= arr[i];
		}
	}

	cout << contador_mayores << " " << contador_menores << '\n';

	return 0;
}