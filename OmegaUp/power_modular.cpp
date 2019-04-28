#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

typedef long double dbl;

int mul(int a, int b, int m) {
    a%=m; if(a<0) a+=m;
    b%=m; if(b<0) b+=m;
    int q = ((dbl)a * (dbl)b) / (dbl)m;
    int r = a*b - q*m;
    return (r<0 ? r+m:r);
}

int pwr(int a, int n, int m) {
    int ans(1);
    while(n) {
        if(n & 1) ans = mul(ans, a, m);
        if(n >>= 1) a = mul(a, a, m);
    }
    return ans%m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cout << pwr(2,2,20) << '\n';
	return 0;
}