#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    switch (t) {
        case 2: {
            string ans = "";
            for(int i = 0; i < n; ++i ) {
                ans = ans + "2";
            }
            cout << ans << '\n';
        } break;
        case 3: {
            string ans = "";
            for(int i = 0; i < n; ++i ) {
                ans = ans + "3";
            }
            cout << ans << '\n';
        } break;
        case 4: {
            string ans = "4";
            for(int i = 0; i < n - 1; ++i ) {
                ans = "2" + ans;
            }
            cout << ans << '\n';
        } break;
        case 5: {
            string ans = "";
            for(int i = 0; i < n; ++i ) {
                ans = ans + "5";
            }
            cout << ans << '\n';
        } break;
        case 6: {
            string ans = "6";
            for(int i = 0; i < n - 1; ++i ) {
                ans = "3" + ans;
            }
            cout << ans << '\n';
        } break;
        case 7: {
            string ans = "";
            for(int i = 0; i < n; ++i ) {
                ans = ans + "7";
            }
            cout << ans << '\n';
        } break;
        case 8: {
            string ans = "";
            for(int i = 0; i < n; ++i ) {
                ans = ans + "8";
            }
            cout << ans << '\n';
        } break;
        case 9: {
            string ans = "";
            for(int i = 0; i < n; ++i ) {
                ans = "9" + ans;
            }
            cout << ans << '\n';
        } break;
        case 10: {
            if(n == 1) {
                cout << -1 << '\n';
                return 0;
            }
            string ans = "0";
            for(int i = 0; i < n - 1; ++i ) {
                ans = "1" + ans ;
            }
            cout << ans << '\n';
        } break;
        default:
            break;
    }
    return 0;
}