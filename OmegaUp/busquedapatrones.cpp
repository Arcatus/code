#include <bits/stdc++.h>

using namespace std;

unsigned int fexp(unsigned int a, unsigned int b) {
	if (b <= 1) {
		return b == 1 ? a: 1;
	}
	unsigned int tmp = fexp(a, b/2);
	tmp *= tmp;
	return tmp * (b & 1 ? a : 1);
}

int varx[1000001];
unsigned int polyRolling (string key, int p, int x, int n)
{
	unsigned int ans = 0;
	for(int i=0; i<n; ++i ) {
		ans += (key[i] * varx[n-i-1]) % p;
	}
	return ans % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string C, S, T;
    int m, n, x, p;
    cin >> m >> C >> n >> S >> x >> p;
    for(int i=0; i<n; ++i) {
        varx[i] = fexp(x,i) % p;
    }
    int sizeC = C.size();
    int sizeS = S.size();
    bool memoria[1<<15]; 
    int cnt = 0;
    int colisiones = 0;
    int hs = polyRolling(S,p,x,n);
    unordered_set<string> cmpp;
    cmpp.insert(S);
    for(int i=0; i<=sizeC-sizeS; ++i ) {
        T = C.substr(i,sizeS);
        if ( cmpp.count(T) > 0 ) {
            cnt++;
        }
        int hc = polyRolling(T,p,x,n);
        if ( hc == hs ) {
            colisiones++;
        }
    }
    cout << colisiones << " " << cnt << '\n';
    return 0;
}