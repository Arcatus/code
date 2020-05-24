#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long div;
    long long n;
    cin >> n >> div;
    int ans = 0;
    int m = 2;
    while( div <= n ) {
        ans += n / div;
    }
    cout << ans << '\n';
    return 0;
}