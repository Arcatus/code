#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int fila[n];
	int columna[n];

	bool mat[n][n];

	memset( mat, false, sizeof mat );

	for (int i=0;i<n;++i) cin >> fila[i];
	for (int i=0;i<n;++i) cin >> columna[i];

	sort(columna,columna+n);
	sort(fila,fila+n);

	for (int i=n-1, k = 0 ;i>=0; --i, ++k) {
		for (int j=n-1;j>=0; --j) {

			if ( fila[i] > columna[j] )
			{				
				mat[k][j] = true;
			}
		}
	}

	int res = 0;

	int i, j;

	for (i=0;i<n;++i) {
		for (j=n-1;j>=0;--j) {
			if ( mat[i][j] )
			{
				vector<int> posibilities;

				for (int inc = i; inc<n; ++inc)
				{
					if (mat[inc][j]) {
						posibilities.push_back(fila[n-inc-1]);
					}
					else break;
				}
			 	res += *max_element(posibilities.begin(),posibilities.end());

				for (int z=j; z>=0; --z) mat[i][z] = false;
				for (int z=i; z <n; ++z) mat[z][j] = false;
				
			}
		}
	}

	cout << res << '\n';

	return 0;
}