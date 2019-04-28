#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int arr[n];
	int brr[n];

	for (int i = 0; i < n; ++i)
	{	
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i)
	{	
		cin >> brr[i];
	}

	sort(arr,arr+n);
	sort(brr,brr+n);

	int index0=n-1, index1=n-1;

	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		while( arr[index0] <= brr[index1] && index1>0)
		{
			index1--;
		}

		if ( index1==0 && index0==n-1 ){ 
			if ( arr[index0] > arr[0])
			{
				res += arr[index0];
			}
			break;
		}
		
		res += arr[index0];
		if (index1==0) break;
		index0--;
	}

	cout << res << '\n';
	
	return 0;
}