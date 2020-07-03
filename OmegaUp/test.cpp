#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n <= 2) {
        cout << "NO\n";
    } else if ( (n-2)%2 == 0 ) {
        cout << "SI\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}