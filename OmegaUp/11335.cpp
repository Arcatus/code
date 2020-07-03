#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if ( abs(a - c) == abs(b - c) ) {
        cout << "raton C\n";
    } else if ( abs(a - c) < abs(b - c) ) {
        cout << "gato A\n";
    } else {
        cout << "gato B\n";
    }
    return 0;
}