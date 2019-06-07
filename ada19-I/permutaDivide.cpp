#include <iostream>
#include <algorithm>

using namespace std;

int n;

int arr[20+1];

void imprime()
{
	for (int i=0;i<n;++i)
		cout << arr[i] << ' ';
	cout << '\n';
}

void permutaciones(int k)
{
	if (k == n) {
		imprime();
		return;
	}
	for (int j=k; j < n; ++j) {
		swap(arr[k],arr[j]);
		if ( k == 0 || (arr[k] + arr[k-1]) % (k+1) == 0 )
		{
			permutaciones(k+1);
		}
		swap(arr[k],arr[j]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;

	for (int i=0; i<n; ++i) {
		arr[i] = i+1;
	}
	permutaciones(0);	

	return 0;
}