#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;


string borra_ceros(string s){
	while(s.length() > 0 && s[0]=='0' )
		s.erase( s.begin() );
	return s;
}

string mult(string a, string b){
	int n = a.size(), m = b.size();
	int t,k,i; string ans(m+n,'0');
	for (int j = m-1; j >= 0; j--){
		for (i = n-1, k = 0 ; i >= 0 ; i--){
			t = (a[i]-'0')*(b[j]-'0');
			t += (ans[i+j+1]-'0') + k;
			ans[i+j+1] = (t%10)+'0';
			k = t/10;
		}
		ans[j] = ( k + '0');
	}
	return ((ans=borra_ceros(ans))=="" ? "0":ans);
}

string binaryExponentiation(string a, int b) {
     if (b == 0) {
          return "1";
     } else if( b == 1) {
          return a;
     }
     string tmp = binaryExponentiation(a, b/2);
     tmp = mult(tmp, tmp);
     if (b & 1) {
          return mult(tmp, a);
     } else {
          return tmp;
     }
}
string p;
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     string a;
     int b;
     cin >> a >> b;
     int maxp = 200;
     vector<int> d(maxp);
     for(int i = 1; i < maxp; ++i) {
             p = binaryExponentiation(a, i);
	     ll cnt = 0;
	     for(int i = 0; i < p.size(); ++i) {
		 cnt += p[i] - '0';
	     }
	     ll ans = cnt;
	     while(ans >= 10) {
		  cnt = 0;
		  while(ans) {
		      cnt += ans%10;
		      ans /= 10;
		  }
		  ans = cnt;
	     }
	     d[i - 1] = ans;
     }
     int cc = 1, x = d[0];
     for(int i = 1; i < maxp; ++i) {
          if (x == d[i]) {
               break;
          } else cc++;
     }
     b = b % cc;
     p = binaryExponentiation(a, b);
	     ll cnt = 0;
	     for(int i = 0; i < p.size(); ++i) {
		 cnt += p[i] - '0';
	     }
	     ll ans = cnt;
	     while(ans >= 10) {
		  cnt = 0;
		  while(ans) {
		      cnt += ans%10;
		      ans /= 10;
		  }
		  ans = cnt;
	     }
	     cout << ans << '\n';
     return 0;
}
