#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int res=0;
	int dias;
	int sobrante=0;
	for(int i=0;i<n;++i) {
		cin >> dias;
		res+=dias/365;

		sobrante += dias%365;
	}

	cout << res + (sobrante/365) << '\n';

	return 0;
}