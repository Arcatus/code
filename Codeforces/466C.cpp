#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    ll A[n];
    A[0] = a[0];
    for(int i = 0; i < n; ++i) {
        A[i] = A[i - 1] + a[i];
    }
    
    return 0;
}