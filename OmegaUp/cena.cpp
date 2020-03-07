#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int arr[n];

	int unos = 0;
	int dos = 0;

	for(int i=0; i<n; ++i)
	{
		cin >> arr[i];
		if ( arr[i] == 1 ) {
			unos++;
		} else {
			dos++;
		}
	}

	for(int i=0; i<unos; ++i) {

	}

	cout << ans << '\n';
}