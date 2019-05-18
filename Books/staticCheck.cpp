	#include <iostream>
//#include <cstdlib>
#include <ctime>

using namespace std;

struct Point { int x, y; };

int main()
{
	//Point p1{ 1, 2.5 };	

	int x = 2.5;

	int a { static_cast<int>(2.5) };

	cout << x << " " << a << '\n';

	cout << RAND_MAX << '\n';

	srand(time(nullptr));

	cout << sizeof rand() << '\n';

	cout << 5.0f / 2 - 1.0f << '\n';

	const int u = 9;

	if ( true or false )
		cout << "false";

	return 0;
}