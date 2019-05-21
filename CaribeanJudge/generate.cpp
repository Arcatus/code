#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	int cases = 10;
	int max_cities = 10000;
	int max_roads = 100000;
	int max_costs = 1000000;

	cout << cases << '\n';

	for (int i=0;i<cases;i++)
	{		
		int n = max_cities;

		int c = max_roads;

		cout << n << '\n';
		cout << c << '\n';

		int a_i, b_i, v_i;

		for (int j=0; j<c;++j)
		{
			 a_i = static_cast<int>(rand() % n);
			 b_i = static_cast<int>(rand() % n);
			 v_i = static_cast<int>(rand() % max_costs)+1;

			 if( a_i == b_i ) {
			 	if (a_i == 0) b_i+=1;
			 	else a_i-=1;
			 }

			 cout << a_i << " " << b_i << " " << v_i << '\n';
		}
		int new_roads = max_roads;

		cout << new_roads << '\n';		

		for (int j=0; j<new_roads;++j)
		{
			 a_i = static_cast<int>(rand() % n);
			 b_i = static_cast<int>(rand() % n);
			 v_i = static_cast<int>(rand() % max_costs)+1;

			 if( a_i == b_i ) {
			 	if (a_i == 0) b_i+=1;
			 	else a_i-=1;
			 }
			 cout << a_i << " " << b_i << " " << v_i << '\n';
		}		
	}

	return 0;
}