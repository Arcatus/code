#include <bits/stdc++.h>

using namespace std;

int min3(int a, int b, int c) {
    return min(a,min(b,c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k2, k3, k5, k6;
    cin >>  k2>> k3>> k5>> k6;
    int ans = 0;
    ans += min3(k2,k5,k6)*256;
    k2 -= min3(k2,k5,k6);
    k5 -= min3(k2,k5,k6);
    k6 -= min3(k2,k5,k6);
    ans += min(k2,k3)*32;
    cout << ans << '\n';
    return 0;
}