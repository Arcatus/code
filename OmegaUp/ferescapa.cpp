#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	int t, r, f;
	std::cin >> t >> r >> f;

	int fer_v = 0;

	bool escape = false; int q_i;

	int avances[t];

	for (int i = 0; i < t; ++i)
	{
		std::cin >> avances[i];
	}

	while( !escape )
	{
		loop:
		int r_t = r;
		int f_t = f;

		for (int i = 0; i < t; i++)
		{
			q_i = avances[i];

			r_t += q_i;
			f_t += fer_v;

			if ( r_t >= f_t )
			{
				fer_v++;
				goto loop;
			}
		}
		escape = true;
	}	
	std::cout << fer_v << '\n';
}