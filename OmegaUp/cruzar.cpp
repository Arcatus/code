#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1000000000;

int n, m;
int array[1000][1000];
int dp[1000][1000];

int minimum_cost(int i, int j)
{   
    if ( i < 0 || j < 0 || i >= n || j >= m) return inf;
    
    if ( i == 0 && j == 0 ) return array[0][0];
    
    
    if ( dp[i][j] !=  -1)
        return dp[i][j];
    else
    {
        dp[i][j] = array[i][j] + min({ minimum_cost(i  ,j-1), 
                                       minimum_cost(i-1,j),   
                                       minimum_cost(i  ,j+1), 
                                       minimum_cost(i+1,j),   
                                     });
        return dp[i][j];
    }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  
  memset ( dp, -1, sizeof dp ); 
  
  for (int i=0; i<n;++i) {
      for (int j=0;j<m;++j) {
          cin >> array[i][j];
      }
  }
  
  int costo = minimum_cost(n-1,m-1);  
  
  cout << costo <<  '\n';
  
  return 0;
}
