#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;

	cin >> n >> a >> b;

	int64_t m_a=0;
	int64_t m_b=0;

	int64_t ans=0;

	if ( a == b ) {
		for (int i = 1; i*a < n ; ++i) {
			m_a += a*i;
		}
		ans = m_a;
	} else {
			if ( a > b ) {
				swap(a,b);	
			}
			set<int> v;
			for (int j=1; j*b < n ; ++j) {
				m_b += b*j;
				v.insert(b*j);
			}
			for (int i=1; i*a < n ; ++i) {
				if ( v.count(i*a) == 0 ){
					m_a += a*i;
				}
			}
			ans += m_a + m_b;
	}
	
	cout << ans << '\n';
}