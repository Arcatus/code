#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int libre = n;
    int days = 1;
    while(libre > 0) {
        libre--;
        if (days % m == 0) {
            libre++;
        }
        days++;
    }
    cout << days - 1 << '\n';
    return 0;
}