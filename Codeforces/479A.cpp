#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int t1 = max( (a*b)*c, (a+b)+c );
    int t2 = max( (a*b)+c, (a+b)*c );
    int t3 = max( a+(b*c), a*(b + c) );
    cout << max(t1,max(t2,t3)) << '\n';
    return 0;
}