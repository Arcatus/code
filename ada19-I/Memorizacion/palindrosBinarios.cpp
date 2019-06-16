#include <iostream>

using namespace std;

int memoria[75+1];

int formas(int k)
{
    if ( k == 0 ) {
        return 1;
    }
    else if ( k == 1 ) {
        return 2;
    }
    else if ( k == 2 ) {
        return 1;
    }
    else if ( k == 3 ) {
        return 3;
    }
    else {
        if ( memoria[k] == -1 )
        {
            memoria[k] = formas(k - 2) + formas(k - 4);
        }
        return memoria[k];
    }
}

int main()
{
    int n;
  
    cin >> n;
    
    for (int i=0;i<=n;++i) {
        memoria[i] = -1;
    }
    cout << formas(n) << '\n';
    
    return 0;
}