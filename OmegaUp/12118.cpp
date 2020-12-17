#include <bits/stdc++.h>

using ll = long long;
using namespace std;

bool es_capicua(ll n) {
    if(n > ll(10e9)) {
        return false;
    }
    string s = to_string(n);
    if(s.size() == 1) return true;
    else if(s.size() == 2) return s[0] == s[1];

    for(int i = 0, j = s.size() - 1; i < j; ++i, --j ) {
        if(s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
	ll n;
	cin >> n;
	while(n <= ll(10e9) && !es_capicua(n)) {
        string tmp = to_string(n);
        reverse(tmp.begin(), tmp.end());
        n += atoll(tmp.c_str());
    }
    if(es_capicua(n)) {
        cout << n << '\n';
    } else {
        cout << -1 << '\n';
    }
}
