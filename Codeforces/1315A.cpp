#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int a, b, x, y;
    while(t--) {
        cin >> a >> b >> x >> y;
        //cerr << a << " " << b << " " << x << " " << y << '\n'; 
        int c = b*(x);
        int d = b*(a-x-1);
        int w = a*(y);
        int z = a*(b-y-1);
        //cerr << x << " " << y << " " << w << " " << z << '\n'; 
        cout << max(max(c,d),max(w,z)) << '\n';
    }
    return 0;
}