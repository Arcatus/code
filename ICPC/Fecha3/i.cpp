#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if(a[0]>=500) {
        cout << a[0]+a[1]+a[2]-300<<'\n';
    } else {
        if(a[0]+a[1]>=500) {
            if(a[2]>=500) {
                cout << a[0]+a[1]-100+a[2]-100<<'\n';
            } else {
                cout <<a[0]+a[1]-100+a[2]<<'\n';
            }
        } else {
            if(a[0]+a[1]+a[2]>=500) {
                cout << a[0]+a[1]+a[2]-100<<'\n';
            } else {
                cout << a[0]+a[1]+a[2]<<'\n';
            }
        }
    }
    return 0;
}