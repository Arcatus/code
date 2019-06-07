#include <iostream>

using namespace std;

int32_t cuenta_bits(int64_t n)
{
	int count = 0;
	while (n) { 
	    n = n & (n-1);
	    count+=1; 
    }
    return count;
}

int64_t counting(int64_t i, const int8_t& x)
{	
	while(i != 1 && i > 1)	
	{
		i = cuenta_bits(i);
	}
	return (i == x)?1:0;
}

int main()
{
	int8_t x;
	int64_t l_o, n_i;

	cin >> l_o >> n_i >> x;

	int64_t res = 0;

	for (int64_t i=l_o; i<= n_i; ++i)
	{
		res += counting(i,x);
	}

	cout << res << '\n';

	return 0;
}