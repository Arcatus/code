#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    int p1 = 0, p2 = 0;
    int ptr1 = 0, ptr2 = n - 1;
    int turno = 1;
    while (ptr1 <= ptr2){
        if (turno&1) {
            if(a[ptr1] > a[ptr2]) {
                p1 += a[ptr1];
                ptr1++;
            } else {
                p1 += a[ptr2];
                ptr2--;
            }            
        } else {
            if(a[ptr1] > a[ptr2]) {
                p2 += a[ptr1];
                ptr1++;
            } else {
                p2 += a[ptr2];
                ptr2--;
            }
        }
        turno++;
    }
    cout << p1 << " " << p2 << '\n';
    return 0;
}