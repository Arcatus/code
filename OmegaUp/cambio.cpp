#include <iostream>

using namespace std;

int main()
{
	long long x, cambio;

	cin >> x;

	long long diez = x/31536000;

	cambio = x%31536000;

	long long cinco = cambio/86400;

	cambio = cambio%86400;

	long long dos = cambio/3600;

	cambio = cambio%3600;

	long long uno = cambio/60;

	cambio = cambio%60;

	cout << diez << " " << cinco  << " " << dos << " " << uno << " " << cambio << '\n';
}