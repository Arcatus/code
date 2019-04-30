#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	queue<int> micola;

	int opc, t;
	int vendidos=0;
	for(int i=0;i<n;++i)
	{
		cin >> opc;

		if (opc==1) {
			cin >> t;
			micola.push(t);
		}
		else if (opc==2) {
			if (!micola.empty()) {
				vendidos += micola.front();
				micola.pop();
			}
		}
		else if (opc==3) {
			cout << micola.size() << '\n';
		}
		else {
			cout << vendidos << '\n';
		}
	}
	return 0;
}
