#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int gana=0, pierde=0;

    int n;
    cin >> n;
    int t;
    for (int i = 0; i < n; ++i)
    {
        cin>>t;
        gana+=t;
        cin>>t;
        pierde+=t;
    }

    if (gana==pierde)
    {
        cout << "INDETERMINADO" << '\n';
    }
    else if (gana > pierde)
    {
        cout << "CULTO" << '\n';
    }   
    else
    {
        cout << "INCULTO" << '\n';
    }

    return 0;
}