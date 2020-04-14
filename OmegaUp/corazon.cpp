#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char a;
    cin >> a;
    string ans = "";
    ans+="   FFFFFF      FFFFF\n";
    ans+="  FFFFFFFF    FFFFFFF\n";
    ans+=" FFFFFFFFFF  FFFFFFFFF\n";
    ans+="FFFFFFFFFFFFFFFFFFFFFFF\n";
    ans+="FFFFFFFFFFFFFFFFFFFFFFF\n";
    ans+=" FFFFFFFFFFFFFFFFFFFFF\n";
    ans+="  FFFFFFFFFFFFFFFFFFF\n";
    ans+="   FFFFFFFFFFFFFFFFF\n";
    ans+="    FFFFFFFFFFFFFFF\n";
    ans+="     FFFFFFFFFFFFF\n";
    ans+="      FFFFFFFFFFF\n";
    ans+="       FFFFFFFFF\n";
    ans+="        FFFFFFF\n";
    ans+="         FFFFF\n";
    ans+="          FFF\n";
    ans+="           F\n";
    for(int i=0; i<ans.size(); ++i) {
        if ( ans[i] == 'F' ) {
            ans[i] = a;
        }
    }
    cout << ans;
    return 0;
}