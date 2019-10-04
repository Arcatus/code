#include <stdio.h>

typedef long long int lld;

int main()
{
    FILE *data = fopen("test","rb");
    FILE *desti = fopen("testout","wb");
    
    fseek (data, 0, SEEK_END);

    lld _file_size = ftell (data);

    rewind (data);    

    int rtp = 1, raw_data = 2;

    char buffer[ raw_data ];
    
    for(int i=rtp; i < _file_size; i+=raw_data) {
        fseek(data,i,SEEK_SET);
        fread(buffer, 1, raw_data, data);
        fwrite(buffer, 1, raw_data, desti);
    }
    
    fclose(data);
    
    return 0;
}