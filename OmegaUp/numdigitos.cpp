#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b;
    cin >> a >> b;
    long long ans = b * log10(a) + 1;
    cout << ans << '\n';
    return 0;
}