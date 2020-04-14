#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    long long a, b, k;
    while(t--)
    {
        cin >> a >> b >> k;
        if (k%2==0) {
            cout << (k/2)*a - (k/2)*b << '\n';
        } else {
            cout << (k/2+1)*a - (k/2)*b << '\n';
        }
    }   
    return 0;
}