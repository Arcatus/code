#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s = "a";
    s.erase(s.find("a"), 1);
    if(s.size()==0) {
        cerr << "si queda cero\n";
    } else {
        cerr << "que paso?\n";
    }
    return 0;
}