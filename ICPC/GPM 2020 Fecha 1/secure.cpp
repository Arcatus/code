#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(string s) {
    int v = 0;
    bool longitud = 0, speciales = 0, mayuscula = 0, minuscula = 0;
    if(s.size() >= 10) longitud = true;
    int digitcount = 0;
    bool noconsecutive = false;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '.' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '/' || s[i] == '(' || s[i] == '&' || s[i] == ')' ) {
            speciales = true;
        }
        else if(islower(s[i])) {
            minuscula = true;
        }
        else if(isupper(s[i])) {
            mayuscula = true;
        }
        else if(isdigit(s[i])) {
            if(i > 0 && isdigit(s[i - 1]) && ((s[i]-'0') == (s[i-1]-'0'+1)) || ((s[i]-'0') == (s[i-1]-'0'-1)) ) {
                noconsecutive = true;
            }
            digitcount++;
        }
    }
    if(longitud) v++;
    if(speciales) v++;
    if(minuscula) v++;
    if(mayuscula) v++;
    if(!noconsecutive && digitcount > 0) v++;
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    for(int i = 1;  i <= n; ++i) {
        cin >> s;
        int v = solve(s);
        if(v == 5) {
            cout << "Assertion number #" << i << ": Strong\n";
        } else if(v == 4) {
            cout << "Assertion number #" << i << ": Good\n";
        } else if(v == 3) {
            cout << "Assertion number #" << i << ": Weak\n";
        } else {
            cout << "Assertion number #" << i << ": Rejected\n";
        }
    }
    return 0;
}