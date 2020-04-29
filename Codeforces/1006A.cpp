#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x;
    for(int i=0; i<n; ++i) {
        cin >> x;
        if (x%2==0) {
            cout << x-1 << ' '; 
        } else {
            cout << x << ' '; 
        }
    }
    cout << '\n';
    return 0;
}