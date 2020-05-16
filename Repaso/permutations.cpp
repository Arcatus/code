#include <bits/stdc++.h>

using namespace std;

int n = 3;
int a[] =  { 1, 2, 3 };

void permuta(int k) {
    if (k == n) {
        for(int i: a) cout << i << ' '; cout << '\n';
    } else {
        for(int i=k; i<n; ++i) {
            swap(a[k],a[i]);
            permuta(k+1);
            swap(a[k],a[i]);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    permuta(0);
    return 0;
}