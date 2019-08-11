#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int x;

	priority_queue<int> heap;

	for (int i=0; i<n; ++i) {
		cin >> x;
		heap.push( x );

		if (heap.size( ) >= 1000) {
			priority_queue<int> reallocate;

			reallocate.push( heap.top() );
			heap.pop();
			reallocate.push( heap.top() );
			heap.pop();

			while ( heap.size() != 2 ) {
				heap.pop();
			}

			reallocate.push( heap.top() );
			heap.pop();
			reallocate.push( heap.top() );
			heap.pop();

			heap.swap( reallocate );
		}
	}
	int tmp_min = -1;
	int tmp_max = heap.top();

	heap.pop();

	tmp_max = heap.top() * tmp_max;	
	
	if ( heap.size() > 1 ) {

		while( heap.size() != 2) {
			heap.pop();
		}
		tmp_min = heap.top();
		heap.pop();
		tmp_min = heap.top() * tmp_min;
		heap.pop();
	}
	cout << max( tmp_max, tmp_min ) << '\n';
}