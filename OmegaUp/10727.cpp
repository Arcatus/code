#include <cstdio>

using namespace std;
using ll = unsigned long long;

int main() {
    ll n;
    scanf("%llu",&n);
    ll a[94];
    a[0] = 0LL;
    a[1] = 1LL;
    if(n == 1) {
        printf("1");
        return 0;
    }
    for(int i = 2; i < 94; ++i) {
        a[i] = a[i - 1] + a[i - 2];
        if (a[i] == n) {
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}