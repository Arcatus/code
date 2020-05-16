#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int donas = n*(k+1);
    int x;
    for(int i=0; i<k; ++i) {
        cin >> x;
        donas -= x;
    }
    cout << donas << '\n';
    return 0;
}