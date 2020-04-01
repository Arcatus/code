#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
#include <map>

typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, x;
    cin >> n >> m;
    int ans = -1;
    for(int i=1; i<=n; ++i) {
        cin >> x;
        if ( x == m )
            ans = i;
    }
    cout << ans << '\n';
}