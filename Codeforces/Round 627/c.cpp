#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        s = "0" + s + "1";
        int ans = 0;
        int contador = 0;
        for(int i=1; i<s.size(); ++i) {
            if ( s[i] == 'L') {
                contador++;
            }
            else if ( s[i] == 'R' || s[i] == '1' ) {
                contador++;
                ans = max(ans,contador);
                contador = 0;
            }
        }
        ans = max(ans,contador);
        cout << ans << '\n';
    }
}