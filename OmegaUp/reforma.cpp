#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int anterior;
	int t, contador=0;

	priority_queue<int> heap;

	anterior=-1;
	for (int i=0;i<n;++i) {
		cin >> t;		
		if ( t < anterior ) {
			contador+=1;
		}
		else {
			heap.push(contador);
			contador=0;
		}
		anterior=t;
	}

	heap.push(contador);
	
	int res = heap.top();
	if (res==0)
		cout << "0\n";
	else
		cout << res + 1 << '\n';

	return 0;
}