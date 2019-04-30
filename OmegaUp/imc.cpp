#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int peso;
	float altura;
	cin >> altura;
	cin >> peso;

	float imc = (float)peso/(altura*altura);

	if (imc<=18.49f) {
		printf("%.2f\nInfra Peso\n",imc);
	}
	else if (imc<=24.99f) 
	{
		printf("%.2f\nPeso Normal\n",imc);
	}
	else if (imc<=29.99f) 
	{
		printf("%.2f\nSobre Peso\n",imc);
	}
	else if (imc<=34.99f) 
	{
		printf("%.2f\nObesidad Leve\n",imc);
	}
	else if (imc<=39.99f) 
	{
		printf("%.2f\nObesidad Media\n",imc);
	}
	else
	{
		printf("%.2f\nObesidad Morbida\n",imc);
	}

	return 0;
}