#include <iostream>
#include <algorithm>

using namespace std;

int n;

int arr[10+1];

int factorial;

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
		factorial+=1;
		return;
	}
	for (int j=k; j < n; ++j) {
		swap(arr[k],arr[j]);
		permutaciones(k+1);
		swap(arr[k],arr[j]);
	}
}

int main()
{
	cin >> n;

	for (int i=0; i<n; ++i) {
		arr[i] = i;
	}

	permutaciones(0);

	cout << "Total hojas " << factorial << '\n';

	return 0;
}