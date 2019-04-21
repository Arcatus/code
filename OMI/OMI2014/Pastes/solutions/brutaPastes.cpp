#include <iostream>

using namespace std;

#define MAXN 1005

int matriz[MAXN][MAXN];
int num[MAXN * MAXN];
int N, M, P, cont;

int main(){
    cin >> N >> M >> P;
    for(int i = N; i > 0; i--)
        for(int j = 1; j <= M; j++)
            matriz[j][i] = ++cont;
    cont = 0;
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++)
            num[++cont] = matriz[i][j];
    while(P--){
        int a;
        cin >> a;
        cout << num[a] << " ";
    }
    cout << endl;
    return 0;
}
