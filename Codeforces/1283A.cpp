#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int h, m;
    while(t--){
        cin >> h >> m;
        cout << (23 - h)*60 + (60-m) << '\n';
    }
    return 0;
}