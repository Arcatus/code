#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int centDolars = n / 100;
	int cambio = n%100;

	int twentDolars = cambio / 20;
	cambio = cambio%20;

	int tenDolars = cambio / 10;
	cambio = cambio%10;

	int fiveDolars = cambio / 5;
	cambio = cambio%5;

	cout << centDolars + twentDolars + tenDolars + fiveDolars + cambio << '\n';
}