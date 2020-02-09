#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int n;

	cin >> n;
	
	int p_0, p_1, v_0, v_1, car;

	float ans  = 3.40282e+038f, x;

	if ( n > 0 )
		cin >> p_0 >> v_0;

	for(int i=1; i<n; i++) {
		cin >> p_1 >> v_1;
		if ( v_0 > v_1 ) {
			x = (float) ( p_1 - p_0 ) / ( v_0 - v_1);
			if ( x < ans ) {
				ans = x;
				car = i;
			}
		}
		p_0 = p_1;
		v_0 = v_1;
	}
	cout << fixed;
	cout << setprecision(3);

	if ( ans > 3.40282e+037f ) {
		cout << "-1\n";
	} else {
		cout << ans << " " << car << " " << car+1 << '\n';
	}
}