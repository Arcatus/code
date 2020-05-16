#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    char s[5000];
    char t[5000];
    scanf("%s",s);
    scanf("%s",t);
    int dp[2][5000];
    int n = strlen(s);
    int m = strlen(t);
    int p1 = 0, p2 = 0;
    int cnt = 5001;
    while ( cnt ) {
        for(int i=m; i>=p2; i--) {
            for(int j=n; j>=p1; j--) {
                if ( i == n || j == m ) {   
                    dp[i&1][j] = 0;
                } else if ( s[j] == t[i] ) {
                    dp[i&1][j] = 1 + dp[(i+1)&1][j+1];
                } else {
                    dp[i&1][j] = max(dp[(i+1)&1][j], dp[i&1][j+1]);
                }
            }
        }
        if ( p1 == 0 && p2 == 0 ) {
            cnt = dp[0][0];
            printf("%d\n", dp[0][0]);
        }
        cnt--;
        while( s[p1] != t[p2] && p2 < n && p1 < m ) {

            if ( dp[p2&1][p1] == dp[p2&1][p1+1] ) {
                p1++;
            } else {
                p2++;
            }
        }
        if ( s[p1] == t[p2] ) {
            printf("%d %d\n", p1++, p2++);
        }
    }
    return 0;
}