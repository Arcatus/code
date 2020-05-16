#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<string> arr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x;
    int a[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }    
    long long ans = 1;
    while(true) {
        if ( a[0] == a[a[0]-1] ) {
            cout << ans << '\n';
            for(int i=0; i<n; ++i) cout << a[i]  << ' '; cout << '\n';
            break;
        } else {
            ans++;
            int p1 = 0, p2 = a[0]-1;
            while ( p1 < p2 ) {
                swap(a[p1],a[p2]);
                p1++; p2--;
            }
        }
    }
    return 0;
}