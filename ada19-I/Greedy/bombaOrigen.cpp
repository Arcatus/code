#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdlib>

using namespace std;

struct robot {
	int posicion;
	int energia;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	std::cin >> n;

	robot robots[n];

	for (int i=0; i<n; ++i)
	{
		std::cin >> robots[i].posicion >> robots[i].energia;
	}
	int max_left = 0;;
	int max_right = max_left;
	int posicion_bombaL = 0;
	int posicion_bombaR = 0;
	
	int permutions[n];
	
	std::iota(permutions,permutions+n,0);

	do
	{
		for (int i=0; i<n; ++i) 
		{
			int energia = robots[permutions[i]].energia;
			int posicion = robots[permutions[i]].posicion;

			int distanceL = abs(posicion - posicion_bombaL);
			int distanceR = abs(posicion - posicion_bombaR);

			if ( distanceL < energia  ) {
				posicion_bombaL -= (energia - distanceL);
			}
			if ( distanceR < energia  ) {
				posicion_bombaR += (energia - distanceR);
			}
		}

	    max_left = std::min(posicion_bombaL,max_left);
		
	    max_right = std::max(posicion_bombaR,max_right);

		posicion_bombaL = posicion_bombaR = 0;
	}
	while( std::next_permutation(permutions,permutions+n) );

	std::cout << max( -max_left, max_right )<< '\n';
}