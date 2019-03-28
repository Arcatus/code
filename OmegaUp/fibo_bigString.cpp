#include <cstdio>
#include <string>
#include <iostream>

typedef unsigned long long llu;

using namespace std;

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

string fib(int n) 
{ 
  string F[2][2] = {{"1","1"},{"1","0"}};
  if (n == 0)
    return "0";
  
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
  
void multiply(string F[2][2], string M[2][2])
{ 
  string x = suma( mult(F[0][0],M[0][0]) , mult(F[0][1],M[1][0]) ); 
  string y = suma( mult(F[0][0],M[0][1]) , mult(F[0][1],M[1][1]) ); 
  string z = suma( mult(F[1][0],M[0][0]) , mult(F[1][1],M[1][0]) ); 
  string w = suma( mult(F[1][0],M[0][1]) , mult(F[1][1],M[1][1]) ); 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 

int main() 
{ 
  llu n;
  cin >> n;
  
  cout << fib(n) << '\n';
}