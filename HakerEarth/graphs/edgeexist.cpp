#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
#include <iomanip>
#include <map>

typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool p[1000+1][1000+1]; memset(p, false, sizeof p );
    int x, y;
    for(int i=0; i<m; ++i) {
        cin >> x >> y;
        p[x][y] = p[y][x] = true;
    }
    int q;
    cin >> q;
    for(int i=0; i<q; ++i) {
        cin >> x >> y;
        if ( p[x][y] ) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}