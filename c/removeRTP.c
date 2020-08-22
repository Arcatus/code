#include <stdio.h>

typedef long long int lld;

int main(int argc, char** argv)
{
    FILE *data  = fopen(argv[1], "rb");
    FILE *desti = fopen(argv[2], "wb");
    
    fseek (data, 0, SEEK_END);

    lld _file_size = ftell (data);

    rewind (data);

    int rtp = 12, raw_data = 160;

    char buffer[ raw_data ];
    
    for(int i=rtp; i < _file_size; i += raw_data+rtp) {
        fseek(data, i, SEEK_SET);
        fread(buffer, 1, raw_data, data);
        fwrite(buffer, 1, raw_data, desti);
    }
    fclose(data);
    fclose(desti);
    
    return 0;
}