#include<iostream> 

using namespace std;

typedef long long ll;
  
ll binomialCoeff(ll n, ll k) 
{ 
  if (k==0LL || k==n) 
    return 1; 
 
  return  binomialCoeff(n-1LL, k-1LL) + binomialCoeff(n-1LL, k); 
} 

int main() 
{ 
	  ll n;
    
    cin >> n;

    cout << binomialCoeff(n+1LL,2LL) << '\n';

    return 0;
}