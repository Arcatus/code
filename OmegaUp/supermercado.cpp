#include <cstdio>

using namespace std;

int main() {
    int x = 0;
    int ans = 0;
    char check;
    while(scanf("%d",&x)==1) {
        ans += x;
        check = getchar();
        if ( check == '\n' ) {
            printf("%d\n",ans);
            ans = 0; 
        }
    }
    return 0;
}