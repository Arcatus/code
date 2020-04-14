#include <bits/stdc++.h>

using namespace std;

string operator*(string a, const int& b) { 
    string ans = ""; for(int i=0; i<b; ++i) ans+=a; return ans; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}