#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, l, c, d, p, nl, np;
    cin >> n>> k>> l>> c>> d>> p>> nl>> np;
    int ml = k*l;
    int s = c*d;
    cout << min(min(ml/nl, s), p/np)/n << '\n';
    return 0;
}