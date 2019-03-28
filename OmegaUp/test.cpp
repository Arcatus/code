#include <cstdio>
#include <string>
#include <iostream>

typedef unsigned long long llu;

using namespace std;

int contador = 0;

void multiply(string F[2][2], string M[2][2]);
  
void power(string F[2][2], llu n);

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

string fib(llu n) 
{ 
  string F[2][2] = {{"1","1"},{"1","0"}};
  
  power(F, n-1);

  return F[0][0]; 
} 

void power(string F[2][2], llu n)
{ 
  if( n == 0 || n == 1)
      return;
  string M[2][2] = {{"1","1"},{"1","0"}};
  
  power(F, n/2);

  multiply(F, F);
  
  if (n%2 != 0) 
     multiply(F, M);
} 

llu mod(string num, llu a)
{ 
    llu res = 0;
    /*
    cout << contador++ << "- size of num: " << num.length() << ' ';
    cout << "before modulation:" << num << ' ';
    */
    for (int i = 0; i < num.length(); i++)
    {
      res = (res*10 + (llu)num[i] - '0') % a;
    }

    //cout << "after modulation:" << to_string(res) << '\n';
    return res; 
}
  
void multiply(string F[2][2],string M[2][2] )
{ 

  string xLeft 
  = to_string( mod (mult( to_string(mod(F[0][0], 1000000007 )) , to_string ( mod( M[0][0] , 1000000007 ) ) ), 1000000007 ) );
  string xRight 
  = to_string( mod (mult( to_string(mod(F[0][1], 1000000007 )) , to_string ( mod( M[1][0] , 1000000007 ) ) ), 1000000007 ) );
  string yLeft 
  = to_string( mod (mult( to_string(mod(F[0][0], 1000000007 )) , to_string ( mod( M[0][1] , 1000000007 ) ) ), 1000000007 ) );
  string yRight 
  = to_string( mod (mult( to_string(mod(F[0][1], 1000000007 )) , to_string ( mod( M[1][1] , 1000000007 ) ) ), 1000000007 ) );
  string zLeft 
  = to_string( mod (mult( to_string(mod(F[1][0], 1000000007 )) , to_string ( mod( M[0][0] , 1000000007 ) ) ), 1000000007 ) );
  string zRight 
  = to_string( mod (mult( to_string(mod(F[1][1], 1000000007 )) , to_string ( mod( M[1][0] , 1000000007 ) ) ), 1000000007 ) );
   string wLeft 
  = to_string( mod (mult( to_string(mod(F[1][0], 1000000007 )) , to_string ( mod( M[0][1] , 1000000007 ) ) ), 1000000007 ) );
  string wRight 
  = to_string( mod (mult( to_string(mod(F[1][1], 1000000007 )) , to_string ( mod( M[1][1] , 1000000007 ) ) ), 1000000007 ) );

//************************************************************************************************

  string x = to_string( mod( suma( to_string( mod(xLeft,1000000007) ), to_string( mod(xRight,1000000007) ) ), 1000000007 ) );
  string y = to_string( mod( suma( to_string( mod(yLeft,1000000007) ), to_string( mod(yRight,1000000007) ) ), 1000000007 ) );
  string z = to_string( mod( suma( to_string( mod(zLeft,1000000007) ), to_string( mod(zRight,1000000007) ) ), 1000000007 ) );
  string w = to_string( mod( suma( to_string( mod(wLeft,1000000007) ), to_string( mod(wRight,1000000007) ) ), 1000000007 ) );

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;

} 

int main() 
{ 
  llu n;
  cin >> n;
  n++;
  cout << fib(n) << '\n';
  
}