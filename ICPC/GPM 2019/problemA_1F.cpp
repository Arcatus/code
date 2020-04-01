#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector< vector<int> > indice(1000000+1);
    int x;
    int arr[n+1];
    int max_val = -1;
    for(int i=1; i<=n; ++i) {
        cin >> arr[i];
        indice[ arr[i] ].push_back(i);
        max_val = max(max_val,arr[i]);
    }
    
    long long ans = 0;

    for(int i=1; i<=n; ++i ) {
        int v = arr[i];
        for(int j=1; j<v-1; ++j) {
            if ( indice[j].size() > 0 ) {
                int pos = upper_bound(indice[j].begin(), indice[j].end(), i ) - indice[j].begin();
                ans += (j-v)*( indice[j].size() - pos );
            }
        }
        for(int j=v+2; j <= min(max_val,1000000+1); ++j) {
            if ( indice[j].size() > 0 ) {
                int pos = upper_bound(indice[j].begin(), indice[j].end(), i ) - indice[j].begin();
                ans += (j-v)*( indice[j].size() - pos );
            }
        }
    }
    cout << ans << '\n';
}
