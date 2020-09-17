#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    int r = 6 - max(x, y) + 1;
    int g = __gcd(r, 6);
    cout << r/g << "/" << 6/g << '\n';
    return 0;
}