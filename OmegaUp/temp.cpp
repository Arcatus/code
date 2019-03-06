#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>
//#include <cmath>

int main()
{
	float peso, estatura;

	std::cin >> peso >> estatura;

	float imc = peso/(estatura*estatura);

	std::cout << imc << '\n';


	if (imc >= 25.0f)
	{
		std::cout << "SOBREPESO"<<'\n';
	}
	else
	{
		std::cout << "NORMAL"<<'\n';	
	}
}