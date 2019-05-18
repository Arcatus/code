#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i;
	cin >> n;
	int arr[n];

	vector<int> pos;

	for (i=0;i<n;++i) cin >> arr[i];

	for (int i=0;i<n;++i) {
		if (arr[i]==5) {
			pos.push_back(i);
		}
	}

	reverse(arr,arr+pos[0]);

	reverse(arr+pos[1]+1,arr+n);
	bool there_is = false;
	for (i=pos[0]+1; i<pos[1];++i ){
		if ( arr[i]== 7) {
			arr[i]=0; 
			there_is=true;
			break;
		}
	}

	if ( ! there_is ) sort(arr+pos[0]+1,arr+pos[1]);

	for (int i=0;i<n;++i)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}