#include <bits/stdc++.h>

using namespace std;

typedef long long int ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull n;
    cin >> n;
    if (n < 10) {
        cout << n << '\n';
    } else {
        string s = to_string(n);
        ull num = s[0] - '0';

        ull alto = num + 1LL;
        ull bajo = num;
        
        string z = string(s.size()-1,'0');
        
        string a = to_string(alto) + z;
        string b = to_string(bajo) + z;

        ull topeAlto = stoull(a,nullptr,10LL);
        ull topebajo = stoull(b,nullptr,10LL);
        
        if ( abs(topeAlto - n) <= abs(topebajo - n) ) {
            cout << topeAlto << '\n';
        } else {
            cout << topebajo << '\n';
        }
    }
    return 0;
}