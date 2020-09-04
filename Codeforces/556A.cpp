#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ceros = count(s.begin(), s.end(), '1');
    int unos = s.size() - ceros;
    int r = min(ceros, unos);
    cout << s.size() - 2*r << '\n';
    return 0;
}