#include <iostream>
#include <string>
#include <ctime>

using namespace std;

typedef unsigned long long llu;

int mod(string num, int a) 
{ 
    int res = 0; 

    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') % a;

    return res; 
}

string borra_ceros(string s){
   while(s.length() > 0 && s[0]=='0' )
      s.erase( s.begin() );
   return s;
}

string mult(string a, string b){

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

string potencia(llu a, llu b)
{

   if (b == 0) {
      return "1";
   } else if (b == 1) {
      return to_string( a );
   } else {

      string temp = potencia(a, b / 2);

      temp = to_string(  mod( temp, 1000007 )  ) ;

      string res = mult( temp, temp );

      if (b % 2 == 1) 
      {
         res = mult( res, to_string(a) );
      }
      return res;
   }
}

int main()
{
   std::ios::sync_with_stdio(false);
   std::cin.tie(0);

   llu a, b;

   cin >> a >> b;

   string resultado = potencia( a , b );

   cout << mod( resultado, 1000007 ) << '\n';

   return 0;
}
