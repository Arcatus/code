#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> a{ 2, 2, 2, 3, 4, 7, 10, 15 };
    if ( upper_bound(a.begin(),a.end(),100) == a.end() ) {
        cout << "el elemento no existe\n";
    }
    int pos = upper_bound(a.begin(), a.end(), 100 ) - a.begin();  
      

    //cout << a.size() - pos << '\n';
    cout << pos << '\n';
}