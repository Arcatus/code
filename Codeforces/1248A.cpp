#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        ll arr[n];
        for(int i = 1; i <= n; ++i) {
            arr[i - 1] = (1 << i);
        }
        ll a = 0, b = 0;
        a = arr[n - 1];
        for(int i = 0; i < n/2 - 1; ++i) {
            a += arr[i];
        }
        for(int i = n/2 - 1; i < n- 1; ++i) {
            b += arr[i];
        }
        cout << abs(a - b) << '\n';
    }
    return 0;
}