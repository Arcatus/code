#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>

using namespace std;

int arr[50+1], brr[50+1];

int backtrackTimer = 0, n;

priority_queue<int> heap;

void batalla(int k)
{	
	//cerr << "k: " << k << " backtrackTimer: " << backtrackTimer << '\n';

	int costo = 0;

	backtrackTimer+=1;
	
	for(int i=k; i >= 0; --i) {
		for (int j=0; j < n; ++j ) {
			//cerr << i << " " <<  j << '\n';
			int x = brr[j];
			if ( arr[i] > brr[j] && brr[j] != -1) {
				costo += arr[i];
				brr[j] = -1;
				batalla(k-1);
				brr[j] = x;
				costo -= arr[i];
			}			
		}
	}

	if (backtrackTimer == n-1) heap.push(costo);

	backtrackTimer-=1;

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i=0;i<n;++i)
	{
		cin >> arr[i];
	}

	for (int i=0;i<n;++i)
	{
		cin >> brr[i];
	}

	sort(arr,arr+n);
	sort(brr,brr+n);	

	batalla(n-1);

	if (heap.empty()) cout<< "vacio \n";
	else cout << heap.top() << '\n';
	
	return 0;
}