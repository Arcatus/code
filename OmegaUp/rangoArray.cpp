#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	int arr[10];
	for(int i=0; i<10; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+10);

	cout << arr[0] << " " << arr[9] << " " << arr[9] - arr[0] << '\n';
}