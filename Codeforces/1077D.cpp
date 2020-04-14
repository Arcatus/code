#include <bits/stdc++.h>

using namespace std;
int cub[200000+5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int x;
    for(int i=0; i<n; ++i) {
        cin >> x;
        cub[x]++;
    }
    priority_queue< pair<int,int> > q;

    for(int i=1; i<=200000; ++i) {
        if ( cub[i] ) {
            for(int j=1; j<=cub[i]; ++j) {
                q.push({ cub[i]/j, i });
            }
        }
    }
    while( k-- ) {
        cout << q.top().second << ' ';
        q.pop();
    }   
    return 0;
}