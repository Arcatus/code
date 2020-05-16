#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        int total = 0;
        for(int i=0; i<n; ++i) {
            cin >> a[i];
            total += a[i];
        }
        int alice = 0, bob = 0;
        int p1 = 0, p2 = n-1;
        int turno = 1;
        int sumaTurno=0, rival=0;
        while( total > 0 ) {
            sumaTurno = 0;
            if ( turno & 1 ) {
                while( sumaTurno <= rival && total > 0 ) {
                    alice += a[p1];
                    sumaTurno += a[p1];
                    total -= a[p1];
                    p1++;
                }
            } else {
                while( sumaTurno <= rival && total > 0 ) {
                    bob += a[p2];
                    sumaTurno += a[p2];
                    total -= a[p2];
                    p2--;
                }
            }
            swap(sumaTurno,rival);
            turno++;
        }
        cout << turno-1 << " " << alice << " " << bob << '\n';
    }
    return 0;
}