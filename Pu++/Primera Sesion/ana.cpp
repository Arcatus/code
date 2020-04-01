#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int s, n, num=1;
    while(t--)
    {
        cin >> s >> n;

        double arr[n];
        for(int i=0; i<n; ++i) {
            cin >> arr[i];
        }
        double tmp=arr[0];
        int ans = 0;

        for(int i=1; i<n; ++i) {
            if ( arr[i] < tmp ) {
                ans = i;
                tmp = arr[i];
            }
        }   
        cout << "Case "<< num++ << ": comprar en dia " << ans+1 << '\n';
    }
}