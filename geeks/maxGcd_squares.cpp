// C++ code for calculating the 
// number of squares 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find number of squares 
int NumberOfSquares(int x, int y) 
{ 
    // Here in built c++ gcd function is used 
    int s = __gcd(x, y); 
  
    int ans = (x * y) / (s * s); 
  
    return ans; 
} 
  
// Driver code 
int main() 
{ 
    int m, n;
	cin >> m >> n;
    // Call the function NumberOfSquares 
    cout << NumberOfSquares(m, n) << '\n';
  
    return 0; 
} 