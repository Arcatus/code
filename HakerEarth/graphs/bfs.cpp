#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <map>

typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n+1);
    int x, y;
    for(int i=0;i<n-1;++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);  
    }
    cin >> x;
    int l[n+5];
    bool z[n+5]; 
    memset(z, false, sizeof z);
    queue<int> q;
    q.push(1);
    l[1] = 1;
    while( !q.empty() ) {
        int v = q.front();
        q.pop();
        for(auto i: a[v]) {
            if ( !z[i] ) {
                z[v] = true;
                l[i] = l[v] + 1;
                q.push(i);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; ++i) {
        if(l[i] == x) ans++;
    }
    cout << ans << '\n';
}