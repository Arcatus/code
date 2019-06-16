#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int,int> ii;

ii memoria[30+1][30+1];

ii binomial(int n, int k)
{   
    if ( k == 0 || k == n )
    {
        return {1,1};
    }   
    else
    {
        if ( memoria[n][k].first == -1 )
        {
            ii x = binomial(n-1,k);
            ii y = binomial(n-1,k-1);
            memoria[n][k] = { x.first + y.first, x.second + y.second + 1};
        }
        return memoria[n][k];
    }
}

int main()
{
    int n, k;
    
    cin >> n >> k;    

    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=k; ++j) {
            memoria[i][j].first = -1;
        }
    }
    
    ii ans = binomial(n,k);
    
    cout<< ans.first << " " << ans.second << '\n';
    
    return 0;
}