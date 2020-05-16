#include <cstdio>

int main() {
    int N, L;    
    scanf("%d %d", &N, &L);
    char buffer[(L * N) + 4*N + N];
    int libres = 0, idx = 0, idusd = 0;
    int id = 0, to_ext, to_del, ini = 0, pos;
    char idc[4];
    char signo, opcion;
    int indexes[N+1] = { };
    int liberados[N+1] = { };
    char var[9];
    char devnull;
    const int offset = 1 + 4 + 8;
    fread(&devnull, 1, 1, stdin);
    for(int i=0; i<N; ++i) {
        fread(&opcion, 1, 1, stdin);
        if ( opcion == 'A' ) {
            fread(&devnull, 1, 1, stdin);
            pos = (int)ftell(stdin);
            fseek(stdin, L, SEEK_CUR);
            to_ext = id++;
            for(int i=3; i>=0; i--) {
                idc[i] = (to_ext % 10)+'0';
                to_ext = to_ext / 10;
            }
            for(int i=7; i>=0; i--) {
                if ( pos > 0 ) {
                    var[i] = (pos % 10)+'0';
                    pos = pos / 10;
                } else {
                    var[i] = '0';
                }
            }
            idc[4] = 0;
            signo = '+';
            if ( idusd < idx ) {
                int lib_ini = liberados[idusd++];
                indexes[id-1] = lib_ini;
                buffer[lib_ini] = signo;
                for(int i=0; i<4; ++i) buffer[lib_ini+1+i] = idc[i];
                for(int i=0; i<8; ++i) buffer[lib_ini+5+i] = var[i];

            } else {
                indexes[id-1] = ini;
                buffer[ini] = signo;
                for(int i=0; i<4; ++i) buffer[ini+1+i] = idc[i];
                for(int i=0; i<8; ++i) buffer[ini+5+i] = var[i];
                ini += offset;
            }
        } else {
            fread(&devnull, 1, 1, stdin);
            scanf("%d",&to_del);
            buffer[ indexes[to_del] ] = '-';
            liberados[idx++] = indexes[to_del];
        }
        fread(&devnull, 1, 1, stdin);
    }
    int factor;
    char palabra[L/2+1];
    for(int i=0; i < ini/offset; i++) {
        fwrite(buffer + i*offset, 5 , 1, stdout);
        pos = 0, factor = 1;
        for(int j=0; j<7; j++) {
            pos += (buffer[(i+1)*offset-1-j] -'0')*(factor);
            factor *= 10;
        }
        fseek(stdin, pos, SEEK_SET);
        fread(palabra, L/2, 1, stdin);
        fwrite(palabra, 1, L/2 , stdout);
        fread(palabra, L - L/2, 1, stdin);
        fwrite(palabra, 1, L - L/2, stdout);
    }
    return 0;
}