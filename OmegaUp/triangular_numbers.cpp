#include<iostream> 

using namespace std;
  
int binomialCoeff(int n, int k) 
{ 
  if (k==0 || k==n) 
    return 1; 
 
  return  binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k); 
} 

int main() 
{ 
	int n, cases;

    cin >> cases;

    for (int i = 0; i < cases; ++i)
    {
    	cin >> n;
    	cout << binomialCoeff(n+1,2) << '\n';
    }
} 