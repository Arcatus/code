#include <bits/stdc++.h>

using namespace std;

int max3(int a, int b, int c) {
    return max(a,max(b,c));
}
int min3(int a, int b, int c) {
    return min(a,min(b,c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int ans = 1e9+1, tmp;
    for(int i=min3(x1,x2,x3); i<=max3(x1,x2,x3); ++i) {
        tmp=0;
        tmp = abs(i-x1);
        tmp += abs(i-x2);
        tmp += abs(i-x3);
        if ( tmp < ans ) {
            ans = tmp;
        }
    }
    cout << ans << '\n';
    return 0;
}