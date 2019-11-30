#include <iostream>
#include <deque>

using namespace std;

char opc[10+1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, num;
	cin >> n;

	deque<int> doble_cola;

	while(n--)
	{
		cin >> opc;
		if (opc[0] == 'A')
		{
			cin >> num;
			if (opc[7] == 'I') doble_cola.push_front(num);
			else doble_cola.push_back(num);
		}
		else if (opc[0] == 'Q')
		{
			if (opc[6] == 'I') doble_cola.pop_front();
			else doble_cola.pop_back();
		}
		else
		{
			if (opc[5] == 'I') {
				doble_cola.push_back(doble_cola.front());
				doble_cola.pop_front();
			}
			else
			{
				doble_cola.push_front(doble_cola.back());
				doble_cola.pop_back();
			}
		}
	}

	for (auto i: doble_cola)
	{
		cout << i << ' ';
	}
	cout << '\n';
}