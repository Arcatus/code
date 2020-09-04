#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n = 500000;
    ll r = 10000;
    ll k = 10000000000000000000ULL;
    cout << n << " " << r << " " << k << '\n';
    srand(time(NULL));
    for(int i = 0; i < n; i++ ) {
        cout << rand() << ' ';
    }
    return 0;
}