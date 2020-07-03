#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    string x, a, b;
    while(t--) {
        cin >> n >> x;
        a=""; b = "";
        int k=0;
        while(k<n) {
            if(x[k]=='0') {
                a+='0'; b+='0';
            } else if( x[k]=='1') {
                a+='0'; b+='1'; k++;
                break;
            } else if( x[k]=='2') {
                a+='1'; b+='1';
            }
            k++;
        }
        for(int i=k; i<n; ++i) {
            if( x[i] == '0' ) {
                a+="0"; b+="0";
            }
            else if( x[i] == '1' ) {
                a+='1'; b+='0';
            }
            else if( x[i] == '2' ) {
                a+='2'; b+='0';
            }
        }
        cout << b << '\n';
        cout << a << '\n';
    }
    return 0;
}