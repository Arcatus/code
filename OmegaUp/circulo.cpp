//#include <iostream>
#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>

//using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	float radio;

	scanf("%f",&radio);	

	float area = 3.1416f * (radio * radio);

	float perimetro =  2.0f * 3.1416f * radio;

	printf("%.2f %.2f\n",area, perimetro );
}