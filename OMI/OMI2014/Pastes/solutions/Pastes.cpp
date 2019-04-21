#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long int N, M;
    cin >> N >> M;
    int p;
    cin >> p;
    while(p--){
        long long int a, b;
        cin >> a;
        b = N - a % N;
        if(b == N)
            b = 0;
        long long int answer = ((a - 1)/ N) + 1 + b * M ;
        cout << answer << " ";
    }
    return 0;
}
