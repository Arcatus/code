#include<iostream> 

using namespace std;

typedef long long ll;
  
ll binomialCoeff(ll n, ll k) 
{ 
  if (k==0LL || k==n) 
    return 1; 
 
  return  binomialCoeff(n-1LL, k-1LL) + binomialCoeff(n-1LL, k); 
} 

int main(int argc, char **argv) 
{ 
	int n = stoi(argv[1]);
    for (int i=0;i<=n;++i) {
    	cout << binomialCoeff(n,i) << '\n';
    }
    return 0;
}