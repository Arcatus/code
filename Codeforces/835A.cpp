#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int p1 = 0, p2=0;
    p1 += 2*t1 + s*v1;
    p2 += 2*t2 + s*v2;
    if ( p1 < p2 ) {
        cout << "First\n";
    } else if ( p2 < p1 ) {
        cout << "Second\n";
    } else {
        cout << "Friendship\n";
    }
    return 0;
}