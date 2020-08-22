#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    int s = min(x, y);
    if( s & 1) {
        cout << "Akshat\n";
    } else {
        cout << "Malvika\n";
    }
    return 0;
}