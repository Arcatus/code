#include <iostream>

using namespace std;

unsigned int countSetBits(int n) 
{ 
    unsigned int count = 0; 
    while (n) 
    { 
	    n &= (n-1);
	    count+=1;
    }
    return count;
}

int main()
{
	int n;
	cin >> n;

	cout << countSetBits(n) << '\n';

	return 0;
}