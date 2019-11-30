#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() 
{
	srand(time(NULL));
	int n; 

	cin >> n;

	int* tablero[n][n];

	vector<int> ptr;

	int offset = 0;
	
	ptr.reserve(100);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			tablero[i][j] = &ptr[i];
		}
		ptr[offset++] = i;
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cout << *tablero[i][j] << ' ';
		}
		cout << '\n';
	}
}