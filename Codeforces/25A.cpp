#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int par=0, impar=0; 
    int a[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        if (a[i]&1) impar++; else par++;
    }
    if ( impar == 1 ) {
        for(int i=0; i<n; ++i) {
            if (a[i]&1) {
                cout << i+1 << '\n';break;
            }
        }   
    } else {
        for(int i=0; i<n; ++i) {
            if (a[i]%2==0) {
                cout << i+1 << '\n';break;
            }
        }
    }
    return 0;
}