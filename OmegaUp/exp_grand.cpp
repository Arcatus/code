#include <climits>
#include <iostream>
#include <string>

using namespace std;

string borra_ceros(string s){
   while(s.length() > 0 && s[0]=='0' )
      s.erase( s.begin() );
   return s;
}

string suma (string a, string b)
{
   int l = 1 + (a.length() > b.length() ? a.length() : b.length());
   string c(l,'0');

   a = string(l - a.length(), '0' ) + a;
   b = string(l - b.length(), '0' ) + b;

   int ac = 0, sum = 0;

   for( int i = l - 1; i >= 0; i-- )
   {
      sum = ( a[i] - '0' ) + ( b[i] - '0') + ac;
      c[i] = (sum % 10) + '0';
      ac = sum / 10;
   }
   return ((c=borra_ceros(c))=="" ? "0":c);
}

string mult(string a, string b) {

   int n = a.size(), m = b.size();
   int t,k,i; string ans(m+n,'0');

   for (int j = m-1; j >= 0; j--)
   {
      for (i = n-1, k = 0 ; i >= 0 ; i--)
      {
         t = (a[i]-'0')*(b[j]-'0');
         
         t += (ans[i+j+1]-'0') + k;
         
         ans[i+j+1] = (t%10)+'0';

         k = t/10;
      }
      ans[j] = ( k + '0');
   }
   return ((ans=borra_ceros(ans))=="" ? "0":ans);
}

int mod(string num, int a) 
{ 
    int res = 0; 

    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') % a;

    return res; 
}

int main()
{
   int n, m;

   cin >> n >> m;

   string res = "1",tmp = "2";

   for (int i = 1; i < n; ++i)
   {
      res = mult(res,tmp);

      tmp = suma(tmp,"1");

   }
   cout << res << '\n';
}