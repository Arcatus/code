#pragma GCC optimize ("Ofast")

#include <iostream>

using namespace std;

int califica(char a) {
	int promedio = 0;
	int cantidad = 0;
	while( a != ')' ) {
		if ( a == '(' ) {
			a = getchar();
			cantidad+=1;
			promedio += califica(a);
			a = getchar();
			continue;
		}
		if ( '0' <= a ) {
			promedio += a-'0';
			cantidad += 1;
		}
		a = getchar();
	}	
	return promedio/cantidad;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char a = getchar();

	int promedio = 0;
	int cantidad = 0;

	while( a != EOF ) {
		if ( a == '(' ) {
			a = getchar();
			cantidad+=1;
			promedio += califica(a);
			a = getchar();
			continue;
		}
		if ( '0' <= a ) {
			promedio += a-'0';
			cantidad += 1;
		}
		a = getchar();
	}
	cout << promedio/cantidad << '\n';
}