#include <iostream>

using namespace std;

typedef long long ll;

long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }

struct GCD_type { long long x, y, d; };

GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    ll a[x+1], n[x+1], ans, lcm;

    while(x--) {
        int t=2;
        for(int i = 1; i <= t; i++) cin >> a[i] >> n[i], normalize(a[i], n[i]);
        ans = a[1];
        lcm = n[1];
        for(int i = 2; i <= t; i++)
        {
            auto pom = ex_GCD(lcm, n[i]);
            int x1 = pom.x;
            int d = pom.d;
            if((a[i] - ans) % d != 0) {
                cout << "no solution\n";
                break;
            } else {
                ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
                lcm = LCM(lcm, n[i]);
                cout << ans << " " << lcm << endl;
            }
        }
    }
}