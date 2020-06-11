#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char d;
    string s = "";
    int ans = 0;
    string k;
    while(getline(cin,k)) {
        for(int i=0; i<k.size(); ++i) {
            if ( 48 <= k[i] && k[i] <= 57) {
                s += k[i];
            } else {
                if (s != "") {
                    ans += (int) stoi(s,nullptr,10);
                } 
                s = "";
            } 
        }
        if (s != "") {
            ans += (int) stoi(s,nullptr,10);
        } 
        s= "";
        cout << ans << '\n';
        ans = 0;
    }
    return 0;
}