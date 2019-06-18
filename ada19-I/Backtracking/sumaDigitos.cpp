#include <iostream>

using namespace std;

int n;

int contador, restante;

void genera(int k)
{
	if (k == n) {
		contador+=1;
		return; 
	}
	for (int i=1;i<=9;++i) {
		if (k + i <= n && ) {
			genera(k+i);
		}
	}
}

int main()
{
	cin >> n;

	genera(0);

	cout << contador << '\n';

	return 0;
}