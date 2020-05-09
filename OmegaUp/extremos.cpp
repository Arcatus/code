#include <cstdio>
#include <cstdint>
#include <inttypes.h>
#include <algorithm>

using namespace std;

int main() {
    int32_t n;
    scanf("%" SCNd32, &n);
    if ( n == 0 ) {
        return 0;
    }
    char a = getchar();
    int k = (int) ftell(stdin);
    int leidosL = 0;
    int leidosR = 0;
    int bkt = 10000;
    int btkBytes = bkt*4;
    char bufferL[bkt*4+5];
    char bufferR[bkt*4+5];
    int i = 0, j;
    int tRight, tLeft;
    while ( i < n-1-i ) {
        fseek(stdin, k+leidosL, SEEK_SET);
        if ( leidosL + btkBytes <= n*4 ) {
            tLeft = bkt;
        } else {
            tLeft = (4*n - leidosL)/4;
        }
        fread(bufferL, tLeft , 4, stdin);
        fseek(stdin, max(k, k + 4*n - leidosR - btkBytes ), SEEK_SET);
        if ( 4*n - leidosR >= btkBytes ) {
            tRight = bkt;
        } else {
            tRight = (4*n - leidosR)/4;
        }
        fread(bufferR, tRight, 4, stdin);
        for(j=0; j < min(bkt, tLeft ) && i < n-1-i; ++j ) {
            fwrite(bufferL+4*j, sizeof(int32_t), 1, stdout);
            fwrite(bufferR+(tRight-j-1)*4 , sizeof(int32_t), 1, stdout);
            i++;
        }
        leidosL += tLeft*4;
        leidosR += tRight*4;    
    }
    if (n%2==1) fwrite(bufferL+4*i, sizeof(int32_t), 1, stdout);
    return 0;
}