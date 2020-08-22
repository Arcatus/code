#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    long long n;
    int cnt = 0;
    while(t--) {
        cin >> n;
        int x = 1;
        int k = 2;
        while( n % ((1LL << k) - 1) != 0) {
            k++;
        }
        cout << n / ((1LL << k) - 1) << '\n';
    }
    return 0;
}