#include <iostream>

using namespace std;

int solve(int n) {
    
    if ( n <= 4 ) {
    	return 4 - n;
    }
    return (n - 4 ) % 2 == 0 ? 0:1;
}

int main()
{
    int q, n;
    cin >> q;

    for(int i=0; i<q; ++i) {
        cin >> n;
        int ans = solve(n);
        cout << ans << '\n';
    }
}