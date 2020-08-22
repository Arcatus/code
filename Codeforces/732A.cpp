#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, r;
    cin >> k >> r;
    int i = 1;
    while(true) {
        if ((i*k % 10) == r || i*k % 10 == 0) {
            cout << i << '\n';
            return 0;
        }
        i++;
    }
    return 0;
}