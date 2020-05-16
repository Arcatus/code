#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int firstImp, firstPar, lastPar, lastImp;
    firstImp = 1;
    firstPar = 2;
    if (n % 2 == 0) {
        lastPar = n;
        lastImp = n-1;
    } else {
        lastPar = n-1;
        lastImp = n;
    }
    if ( abs(lastImp - firstPar ) == 1 && abs(lastImp - lastPar ) == 1 && 
            abs(firstImp - firstPar ) == 1 && abs(firstImp - lastPar ) == 1 ) {
            cout << "NO SOLUTION\n";
    } else {
        if ( abs(lastImp - firstPar ) > 1 ) {
            for(int i=firstImp; i <= lastImp; i+=2) cout << i << ' ';
            for(int i=firstPar; i <= lastPar; i+=2) cout << i << ' ';
        } else if ( abs(lastImp - lastPar ) > 1 ) {
            for(int i=firstImp; i <= lastImp; i+=2) cout << i << ' ';
            for(int i=lastPar;  i >= firstPar; i-=2) cout << i << ' ';
        } else if ( abs(firstImp - firstPar ) > 1 ) {
            for(int i=lastPar;  i >= firstPar; i-=2) cout << i << ' ';
            for(int i=firstImp; i <= lastImp; i+=2) cout << i << ' ';
        } else {
            for(int i=firstPar; i <= lastPar; i+=2) cout << i << ' ';
            for(int i=firstImp; i <= lastImp; i+=2) cout << i << ' ';
        }
    }
    return 0;
}