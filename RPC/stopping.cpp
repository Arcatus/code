#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int miles, gas, food;
    cin >> miles >> gas >> food;
    assert(miles <= 1000);
    bool stops[1001] = { };
    for(int i = gas; i < miles; i+=gas) {
        stops[i] = true;
    }
    for(int i = food; i < miles; i+=food) {
        stops[i] = true;
    }
    int ans = 0;
    for(int i = 1; i < miles; ++i ) {
        ans += stops[i];
    }
    cout << ans << '\n';
    return 0;
}