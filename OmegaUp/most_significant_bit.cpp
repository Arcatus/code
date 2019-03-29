#include <iostream>

using namespace std; 

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 
  
unsigned int setBitNumber(unsigned int n) 
{ 
    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(n));
    n |= n >> 1; 

    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(n));
  
    n |= n >> 2; 

    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(n));
  
    n |= n >> 4; 

    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(n));

    n |= n >> 8; 

    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(n));

    n |= n >> 16; 

    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(n));

    n = n + 1; 

    int MSB = n >> 1;

    printf(BYTE_TO_BINARY_PATTERN,BYTE_TO_BINARY(MSB));

    return (n >> 1); 
} 

int main() 
{ 
    unsigned int n;

    cin >> n;
    cout << setBitNumber(n) << '\n'; 
    return 0; 
} 